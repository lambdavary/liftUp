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
from gazebo_msgs.msg import ModelStates
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import socket

class image_feature:

    def __init__(self):
        self.pub_modelstate = rospy.Publisher( '/gazebo/set_model_state', ModelState, queue_size=10)
        self.currentPosition = 0.0
        self.bridge = CvBridge()
        self.subscriber = rospy.Subscriber("/camera/image_raw",
            Image, self.callback,  queue_size = 1)


    def callback(self, ros_data):

        cv_image = self.bridge.imgmsg_to_cv2(ros_data, "bgr8")
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        circles = cv2.HoughCircles(gray,cv2.HOUGH_GRADIENT,2,400, param1=50,param2=10,minRadius=10,maxRadius=100)

        if self.currentPosition - int(data) < 10 :
            print(circles)
            if circles is not None:
                xPos = -5.983*10**-7*circles[0][0][2]**5 + 0.0001086*circles[0][0][2]**4 - 0.00788*circles[0][0][2]**3 + 0.292*circles[0][0][2]**2 - 5.812*circles[0][0][2] + 59
                if xPos > 10:
                    self.currentPosition = self.currentPosition + 1
                else:
                    self.currentPosition = self.currentPosition + 0.5
                modelState = ModelState()
                modelState.model_name = 'yau'
                modelState.pose.position.x = self.currentPosition
                modelState.pose.position.y = 0
                modelState.pose.position.z = 5
                self.pub_modelstate.publish(modelState)
            else:
                self.currentPosition = self.currentPosition + 0.01

                modelState = ModelState()
                modelState.model_name = 'yau'
                modelState.pose.position.x = self.currentPosition
                modelState.pose.position.y = 0
                modelState.pose.position.z = 5
                self.pub_modelstate.publish(modelState)

        else:
            modelState = ModelState()
            modelState.model_name = 'yau'
            modelState.pose.position.x = self.currentPosition
            modelState.pose.position.y = 0
            modelState.pose.position.z = 5
            self.pub_modelstate.publish(modelState)
            self.currentPosition = self.currentPosition + 1

class PositionSubscriber:

    def subscribe_position(self):
        # self.subscriber = rospy.Subscriber("/gazebo/model_states", ModelStates, self.callback,  queue_size = 1)
        pos = rospy.wait_for_message("/gazebo/model_states", ModelStates)
        return pos

    # def callback(self, ros_data):
    #     print(ros_data)

def main(args):
    rospy.init_node('gazebo', anonymous=True)
    pub_modelstate = rospy.Publisher( '/gazebo/set_model_state', ModelState, queue_size=10)
    ps = PositionSubscriber()
    
    
    while True:
        pos = ps.subscribe_position()
        yauPosition = pos.pose[1].position
        tankerPosition = pos.pose[2].position
        diffX = tankerPosition.x - yauPosition.x
        diffY = tankerPosition.y - yauPosition.y
        diffZ = tankerPosition.z - yauPosition.z
	print(diffX)
	print(diffY)
	print(diffZ)

        if diffX > 5:
	    
            while diffY > 0.2 or diffY < -0.2:
                k = 0.1
                if diffY > 0:
                    k = -k
		modelState = ModelState()
                modelState.model_name = 'yau'
                quaternion = quaternion_from_euler(k, 0, 0)
		yauPosition.x = yauPosition.x + 0.01
		yauPosition.y = yauPosition.y - k
		yauPosition.z = yauPosition.z - 0.05
		modelState.pose.position.x = yauPosition.x + 0.3
                modelState.pose.position.y = yauPosition.y
                modelState.pose.position.z = 2
                modelState.pose.orientation.x = quaternion[0]
                modelState.pose.orientation.y = quaternion[1]
                modelState.pose.orientation.z = quaternion[2]
                modelState.pose.orientation.w = quaternion[3]
		pub_modelstate.publish(modelState)
		diffY = tankerPosition.y - yauPosition.y
		sleep(0.1)
		print(diffY)

	    modelState = ModelState()
            modelState.model_name = 'yau'
            modelState.pose.position.x = yauPosition.x + 0.1
	    quaternion = quaternion_from_euler(0, 0, 0)
	    modelState.pose.position.y = yauPosition.y
            modelState.pose.position.z = 2
            modelState.pose.orientation.x = quaternion[0]
            modelState.pose.orientation.y = quaternion[1]
            modelState.pose.orientation.z = quaternion[2]
            modelState.pose.orientation.w = quaternion[3]
   	    pub_modelstate.publish(modelState)



        #else:
            #ic = image_feature()
            
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down vison node.")
    
if __name__ == '__main__':
    main(sys.argv)
