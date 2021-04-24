import sys, time
import numpy as np
from scipy.ndimage import filters
import cv2
import roslib
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from threading import Thread
from time import sleep
from gazebo_msgs.msg import ModelState


rospy.init_node('gazebo', anonymous=True)

pub_modelstate = rospy.Publisher( '/gazebo/set_model_state', ModelState, queue_size=10)

for i in range(0, 1000):
    modelState = ModelState()
    modelState.model_name = 'drogue'
    modelState.pose.position.x = i
    modelState.pose.position.y = 0
    pub_modelstate.publish(modelState)
    sleep(0.1)
print('finished')
try:
    rospy.spin()
except KeyboardInterrupt:
    print("Shutting down vison node.")