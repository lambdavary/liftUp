rosinit
positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');
initialPos = 4;

for i=0:10000
    initialPos = initialPos + 0.1;
    pointMsg.ModelName = 'drogue';
    pointMsg.Pose.Position.X = initialPos;
    pointMsg.Pose.Position.Y = 0;
    pointMsg.Pose.Position.Z = 1.5;
    send(positionPublisher,pointMsg);
end
