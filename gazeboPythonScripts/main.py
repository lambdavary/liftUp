import sys, time
import numpy as np
from scipy.ndimage import filters
import cv2
import roslib
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class image_feature:

    def __init__(self):
        rospy.init_node('gazebo', anonymous=True)
        self.bridge = CvBridge()
        self.subscriber = rospy.Subscriber("/camera/image_raw",
            Image, self.callback,  queue_size = 1)


    def callback(self, ros_data):
        print('processing')
        cv_image = self.bridge.imgmsg_to_cv2(ros_data, "bgr8")
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        circles = cv2.HoughCircles(gray,cv2.HOUGH_GRADIENT,2,400, param1=50,param2=10,minRadius=10,maxRadius=100)
        print(circles[0])

def main(args):
    ic = image_feature()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down vison node.")
    

if __name__ == '__main__':
    main(sys.argv)