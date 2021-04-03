function y = setYAUPosition(u)
positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');
pointMsg.ModelName = 'tanker';
pointMsg.Pose.Position.X = u(1);
pointMsg.Pose.Position.Y = u(2);
pointMsg.Pose.Position.Z = u(3);
send(positionPublisher,pointMsg);
y = 0;