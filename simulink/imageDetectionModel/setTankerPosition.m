function y = setTankerPosition(u)
poseSubs = rossubscriber('/gazebo/model_states');
positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');
pointMsg.ModelName = 'drogue';
pointMsg.Pose.Position.X = poseSubs.LatestMessage.Pose(3).Position.X+0.1;
pointMsg.Pose.Position.Y = u(2);
pointMsg.Pose.Position.Z = u(3);
send(positionPublisher,pointMsg);
y = 0;