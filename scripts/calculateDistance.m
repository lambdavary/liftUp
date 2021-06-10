rosinit;
imageSubscriber = rossubscriber('/camera/image_raw');
positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');

distance = [];
radius = [];

for i=2:0.1:30
    distance = [distance, i];
    pointMsg.ModelName = 'drogue';
    pointMsg.Pose.Position.X = i;
    send(positionPublisher,pointMsg);
    receive(imageSubscriber,1);
    [centersDark, radiiDark] = imfindcircles(readImage(imageSubscriber.LatestMessage),[10 300],'ObjectPolarity','dark');
    if isempty(radiiDark)
        radius = [radius, 0];
    else
        radius = [radius, radiiDark];
    end
end 

//x = -5.983*10^-7*radiiDark^5 + 0.0001086*radiiDark^4 - 0.00788*radiiDark^3 + 0.292*radiiDark^2 - 5.812*radiiDark + 59
//y = (320-centersDark(1))/(2*radiiDark)
//z = (240-centersDark(2))/(1.5*radiiDark)
