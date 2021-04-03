rosinit
positionPublisher = rospublisher('/gazebo/set_model_state','gazebo_msgs/ModelState')
pointMsg = rosmessage('gazebo_msgs/ModelState')
pointMsg.ModelName = 'cessna'
pointMsg.Pose.Position.X = 1
send(positionPublisher,pointMsg)
