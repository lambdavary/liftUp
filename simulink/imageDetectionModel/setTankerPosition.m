function y = setTankerPosition(u)
poseSubs = rossubscriber('/gazebo/model_states');
positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState');
pointMsg = rosmessage('gazebo_msgs/ModelState');
pointMsg.ModelName = 'drogue';
pointMsg.Pose.Position.X = poseSubs.LatestMessage.Pose(2).Position.X+1;
pointMsg.Pose.Position.Y = 0;
pointMsg.Pose.Position.Z = 0.5;
pointMsg.Twist.Angular.X = 0;
pointMsg.Twist.Angular.Y = 0;
pointMsg.Twist.Angular.Z = 0;
send(positionPublisher,pointMsg);
y = 0;