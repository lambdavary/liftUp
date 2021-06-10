function y = detectDrogue(u)
[centersDark, radiiDark] = imfindcircles(u,[10 300],'ObjectPolarity','dark');
if ~isempty(centersDark)
xPos = -5.983*10^-7*radiiDark^5 + 0.0001086*radiiDark^4 - 0.0788*radiiDark^3 + 0.292*radiiDark^2 - 5.812*radiiDark + 59;
yPos = (320-centersDark(1))/(2*radiiDark);
zPos = (240-centersDark(2))/(1.5*radiiDark);
y = [xPos yPos zPos];
end
y = [0 0 0];