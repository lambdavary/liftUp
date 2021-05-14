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
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import math

pitch = yaw = 0.0

rospy.init_node('gazebo', anonymous=True)

pub_modelstate = rospy.Publisher( '/gazebo/set_model_state', ModelState, queue_size=10)
i = 10
while True:
    # quaternion = quaternion_from_euler(i%90, pitch, yaw)

    modelState = ModelState()
    modelState.model_name = 'tanker'
    modelState.pose.position.x = 10+i/5000
    modelState.pose.position.y = 1
    modelState.pose.position.z = 3
    # modelState.pose.orientation.x = quaternion[0]
    # modelState.pose.orientation.y = quaternion[1]
    # modelState.pose.orientation.z = quaternion[2]
    # modelState.pose.orientation.w = quaternion[3]
    pub_modelstate.publish(modelState)
    i = i+1

# for i in range(10, 10000):
    
#     sleep(0.1)
# print('finished')
try:
    rospy.spin()
except KeyboardInterrupt:
    print("Shutting down vison node.")
