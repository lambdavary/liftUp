function [XDOT] = Boeing757_MathematicalModel_4(X,U) %X is state vector and U is the control vector

%--------------------Boeing 757--------------------%

%% Definition of State and Control Vectors

x1 = X(1);  %u
x2 = X(2);  %v
x3 = X(3);  %w
x4 = X(4);  %p
x5 = X(5);  %q
x6 = X(6);  %r
x7 = X(7);  %phi
x8 = X(8);  %theta
x9 = X(9);  %psi
%mass (kg)

u1 = U(1);  % Deflection of aileron(d_A)
u2 = U(2);  % Deflection of horizontal stabilizer(d_T) [elevator/tail]
u3 = U(3);  % Deflection of rudder(d_R)
u4 = U(4);  % Changing of throttle 1 
u5 = U(5);  % Changing of throttle 2

%% Constants of A/C

m = 120000; % A/C total mass (kg) but in forward it will be converted to lb


MAC= 6.6;       %Mean aerodynamic chord
lt  = 24.8;     %Distance between AC of tail and aircraft AC
S = 260;        %Wing area (m^2)
St = 64;        %Tail area (m^2)
b_ref = 38.5;   %Wing span (m)

Xcg = 0.23*MAC; %x position of CoG 
Ycg = 0;        %y position of CoG 
Zcg = 0.1*MAC;  %z position of CoG 

Xac = 0.12*MAC; %x position of AC
Yac = 0;        %y position of AC
Zac = 0;        %z position of AC

% Engine Location Parameters 
Xapt1 = 0;      %x position of engine 1 (m)
Yapt1 = -7.94;  %y position of engine 1 (m)
Zapt1 = 1.9;   %z position of engine 1 (m)

Xapt2 = 0;      %x position of engine 2 (m)
Yapt2 = 7.94;  %y position of engine 2 (m)
Zapt2 = 1.9;   %z position of engine 2 (m)

%% Other Constans For A/C

rho = 1.225;                 %Air density (kg/m^3)
g = 9.81;                    %Gravitational acceleration (m/s^2)
W = m*g;
%% Lift From Tail Constans

d_Eps_d_A = 0.25;            %(deltaEpsilon/deltaAlpha) --> Change in downwash w.r.t. alpha (rad/rad) 

%% Lift of Wing Body

alpha_L0 = -11.5*(pi/180);   %Zero lift angle of attack (rad)
n = 5.5;                     %Slope of "Cl_wb vs AoA(deg) Graph"                   
a0 = 15.212;                 %Coefficient of Alpha^0 
a1 = -155.2;                 %Coefficient of Alpha^1 
a2 = 609.2;                 %Coefficient of Alpha^2
a3 = -768.5;                 %Coefficient of Alpha^3
alphaSwitch = 14.5*(pi/180);  %Alpha max value for linear value, if we exceed that, graph will be non-linear


%% Step 2 -- Obtaining Intermediate Variables

%Calculate Airspeed

Va = sqrt(x1^2 + x2^2 + x3^2 );  %(m/s)

%Calculate AoA(alpha) and Side Slipe Angle(Beta)
if Va == 0
    Va = 0.001;
end
alpha = atan2(x3,x1);
beta = asin(x2/Va);     %X1 = u ,X2 = v and X3 = w in Body Frame Translational Velocity (m/s)


%Calculate Dynamic Pressure

Q = 0.5*rho*Va^2; 


%Angular Velocity Vector Body Frame w.r.t. Earth Fixed Frame in Body Axis
%(Wbe_b) and Velocity Vector w.r.t. Body Frame (V_b)

Wbe_b = [x4;x5;x6];
V_b = [x1;x2;x3];

%% Step 3 -- Non Dimensional Aero Force Coefficients 

%Calculate Coefficient of Wing-Body (CL_wb)

if alpha<=alphaSwitch
    CL_wb = n*(alpha-alpha_L0);
else
    CL_wb = a3*alpha^3 + a2*alpha^2 + a1*alpha + a0;
end

%Calculate Coefficient of Tail (CL_t)

epsilon = d_Eps_d_A * (alpha - alpha_L0);
alpha_t = alpha - epsilon + u2 + 1.3 * x5 * (lt/Va); % Alpha tail calculation
CL_t = 3.1*(St/S)*alpha_t;

%Total Lift Force Coefficient

CL = CL_wb + CL_t;

%Total DragForce Coefficient

CD = 0.13 + 0.07 * (5.5*alpha + 0.654)^2;

%Calculate SideForce Coefficient

CY = -1.6*beta + 0.24*u3;

%% Step 4 -- Dimensional Aerodynamic Forces

%Calculate the actual dimensional forces. These are in F_s (stability axis)
%For more detail (https://jsbsim-team.github.io/jsbsim-reference-manual/mypages/user-manual-frames-of-reference/)

FA_s = [-CD*Q*S;
         CY*Q*S;
         -CL*Q*S]; %FA_s: Total aerodynamic forces in stability axis frame. 
                    ...direction of gravitation is positive so FA_s in Z component
                    ... has negative sign

% Applying tranformation matrix from F_s to F_b(body frame)

C_bs = [cos(alpha) 0 -sin(alpha);
            0      1       0;
        sin(alpha) 0  cos(alpha)]; %C_bs : Transformation matrix from stability axis to body frame axis

    
FA_b = C_bs*FA_s;
%% Step 5 -- Non Dimensional Aero Moment Coefficient About Aerodynamic Center of A/C in body axis frame (F_b)

eta1 = -1.4*beta;                                              %Static roll effect of modelling A/C
eta2 = -0.59 - 3.1 * ( (St*lt)/(S*MAC) ) * (alpha - epsilon);  %Static pitch effect of modelling A/C
eta3 = (1 - ( (alpha*180)/(15*pi) ) )*beta;                    %Static yaw effect of modelling A/C


eta = [eta1; eta2; eta3]; % The real notation is transpoze of that

dCM_dx = (MAC/Va) * [-11            0                    5;
                       0  -4.03*( (St*lt^2)/(S*MAC^2) )  0;
                     1.7            0                  -11.5]; % This variable namely dCM_dx is changing rate of the CM w.r.t. state vectors of [x4;x5;x6] = [p;q;r]

dCM_du = [-0.6          0                 0.22;
            0   -3.1*( (St*lt)/(S*MAC) )    0;
            0           0                -0.63]; % dCM_du is defining that if control surface will move, these how much effects the moments of A/C. Because u is control vector and we obtain Aerodynamic Moment w.r.t. changing of u vector


% Calculate the CM = [Cl;Cm;Cn] about Aerodynamic Center in body frame        

CM_ac_b =  eta + dCM_dx * Wbe_b + dCM_du * [u1;u2;u3]; 


%% Step 6 -- Aerodynamic Moment About Aerodynamic Center of A/C

% MA_ac_b = [0;0;0];                            % Altough pitching moment require the Mean Aerodynamic Chord length, yawing moment and rolling moment requires the wing span length
% 
% MA_ac_b(1,1) = CM_ac_b(1)*Q*S*b_ref;          %Roll moment
% MA_ac_b(2,1) = CM_ac_b(2)*Q*S*MAC;            % Pitch moment
% MA_ac_b(3,1) = CM_ac_b(3)*Q*S*b_ref;          % Yaw moment

MA_ac_b = CM_ac_b*Q*S*MAC; % Simplified equation

%% Step 7 -- Aerodynamic Moments About Center of Gravity in Body Frame

rcg_b = [Xcg; Ycg; Zcg];                       % Position of CoG in F_b
rac_b = [Xac; Yac; Zac];                       % Position of AC in F_b
MA_cg_b = MA_ac_b + cross(FA_b, rcg_b-rac_b); % Aerodynamic moment about CoG in F_b

%% Step 8 -- Propulsion Effects 

% Now effect of engine. First, calculate the thrust of each engine 

F1 = u4*m*g; % u4 is the thrust input of first engine
F2 = u5*m*g; % u5 is the thrust input of second engine

%Assuming that engine thrust is aligned with F_b, we have 

FE1_b = [F1; 0; 0];      % Produced thrust from first engine 
FE2_b = [F2; 0; 0];      % Produced thrust from second engine

FE_b = FE1_b + FE2_b;   % Propulsive engine force in F_b

%Now engine moment due to offset of engine thrust from CoG

mew1 = [Xcg - Xapt1;
        Yapt1 - Ycg; 
        Zcg - Zapt1]; % Moment arm (m)

mew2 = [Xcg - Xapt2;
        Yapt2 - Ycg; 
        Zcg - Zapt2]; % Moment arm (m)

ME_cg1_b = cross(mew1, FE1_b); % Propulsive engine moment about CoG in F_b
ME_cg2_b = cross(mew2, FE2_b); % Propulsive engine moment about CoG in F_b 

ME_cg_b = ME_cg1_b + ME_cg2_b; % Total propulsive engine moment about CoG in F_b

%% Step 9 --Gravity Effects

% Calculate gravitational forces in the body frame. This causes no moment
% about CoG

g_b = [-g*sin(x8);
        g*cos(x8)*sin(x7);
        g*cos(x8)*cos(x7)]; 

Fg_b = m*g_b;  

%% Step 10 --State Derivatives 

%Inertia matrix in body frame

Ib = m*[40.07 0 -2.0923;
        0 64 0;
       -2.0923 0 99.92];  
   
%Inverse of inertia matrix

invIb = (1/m)*[0.0249836     0   0.00052315;
                    0    0.015625      0;
               0.00052315    0   0.010019]; % To reduce the calculation time we define it
           
%Form F_b (all the forces in F_b) and calculate uDot, vDot, wDot

F_b = Fg_b + FE_b + FA_b; % Fg_b: Gravitational Forces, FE_b: Engine forces, FA_b: Aerodynamic forces

x1to3dot = (1/m)*F_b - cross(Wbe_b,V_b); % Calculation of uDot, vDot, wDot


%Form Mcg_b (all moments about CoG in F_b) and calculate pDot, qDot and rDot

Mcg_b = MA_cg_b + ME_cg_b; % Total moment about CoG

x4to6dot = invIb * (Mcg_b - cross(Wbe_b,Ib*V_b) ); % pDot, qDot and rDot

% Calculate the phiDot, thetaDot and psiDot

H_phi = [1   sin(x7)*tan(x8)   cos(x7)*tan(x8);
         0        cos(x7)           -sin(x7); 
         0   sin(x7)/cos(x8)    cos(x7)/cos(x8)]; % x7 = phi, x8 = teta, x9 = psi

x7to9dot = H_phi*Wbe_b; % Wbe_b = [p;q;r] , H_phi = transformation matrix

XDOT = [x1to3dot
        x4to6dot
        x7to9dot];
    
end