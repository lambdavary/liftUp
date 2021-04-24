poseSubs = rossubscriber('/gazebo/model_states');
imageSubscriber = rossubscriber('/camera/image_raw');

positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');
initialPos = 4;
init = 0;
for i=0:0.1:10000
    initialPos = initialPos + 0.1;
    init = init +0.1;
    pointMsg.ModelName = 'drogue';
    pointMsg.Pose.Position.X = initialPos;
    pointMsg.Pose.Position.Y = 0;
    pointMsg.Pose.Position.Z = 0.5;
    send(positionPublisher,pointMsg);
    
    receive(imageSubscriber,0.5);
    [centersDark, radiiDark] = imfindcircles(readImage(imageSubscriber.LatestMessage),[10 300],'ObjectPolarity','dark');
    if ~isempty(centersDark)
    xPos = -5.983*10^-7*radiiDark^5 + 0.0001086*radiiDark^4 - 0.00788*radiiDark^3 + 0.292*radiiDark^2 - 5.812*radiiDark + 59;
    yPos = (320-centersDark(1))/(2*radiiDark);
    zPos = (240-centersDark(2))/(1.5*radiiDark);
    y = [xPos yPos zPos]
    end
    
    pointMsg.ModelName = 'tanker';
    pointMsg.Pose.Position.X = init;
    pointMsg.Pose.Position.Y = 0;
    pointMsg.Pose.Position.Z = 0.025;
    send(positionPublisher,pointMsg);
    i
end