rosinit
subs = rossubscriber('/camera/image_raw')
receive(subs,10)
img = readImage(subs.LatestMessage)
[centersDark, radiiDark] = imfindcircles(img,[10 300],'ObjectPolarity','dark');

imshow(img);
hold on
t=0:0.1:2*pi;
%x_o and y_o = center of circle
x = centersDark(1) + radiiDark*sin(t);
y = centersDark(2) + radiiDark*cos(t);
plot(x,y,'r');
hold off
