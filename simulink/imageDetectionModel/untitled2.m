positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');
initialPos = 0;

for i=0:10000
    initialPos = initialPos + 0.01;
    pointMsg.ModelName = 'tanker';
    pointMsg.Pose.Position.X = initialPos;
    pointMsg.Pose.Position.Z = 2;
    pointMsg.Twist.Angular.X = 1;
    send(positionPublisher,pointMsg);
end