load("LastTrimPoint");
load("LastLinearModel");

%% Saturation
 
 %--Aileron
 
u1min = deg2rad(-25);       
u1max = deg2rad(25);        %Deflection of aileron limits in rad

%--Horizantal Stabilizer

u2min = deg2rad(-25);       
u2max = deg2rad(10);        %Deflection of tail/elevator limits in rad

%--Rudder
 
u3min = deg2rad(-30);       
u3max = deg2rad(30);        %Deflection of rudder limits in rad

%--Throttle 1
 
u4min = 0;       
u4max = deg2rad(20);        %Change of thrust limits as a signal not actual value

%--Throttle 2
 
u5min = 0;       
u5max = deg2rad(20);        %Change of thrust limits as a signal not actual value

linsys1 = LastLinearModel;
% linsys2 = Lateral_Dynamics;

A_1 = linsys1.A;
B_1 = linsys1.B;
C_1 = linsys1.C;
D_1 = linsys1.D;

% A_Lat = linsys2.A;
% B_Lat = linsys2.B;
% C_Lat = linsys2.C;
% D_Lat = linsys2.D;

% x0_Long = [];
% % x0_Lat = [];
% u0 = [];

fileName = LastTrimPoint; % Initial states and inputs

% x0_Long = fileName.States(1).x; 
% x0_Long = x0_Long(1:8)

% x0_Lat = fileName.States(1).x;   
% x0_Lat = x0_Lat(1:8);

for i=1:9

    x0(i)=fileName.States(i).x;
    
end

for k=1:4
   u0(k,:) = fileName.Inputs(k).u;
end

u0_Aileron = fileName.Inputs(1).u;
u0_Elevator = fileName.Inputs(2).u;
u0_Rudder = fileName.Inputs(3).u;
u0_Thrust = fileName.Inputs(4).u;


desiredTheta =  x0(8);

