clear; clc;
%% FOLLOWER Aircraft Specifications:

m=1814.37; %kg
Ix=1084.65; %kg.m^2
Iy=6507.93; %kg.m^2
Iz=7050.25; %kg.m^2

S=12.64; %m^2
b=8.02; %m
c=1.65; %m

%% Cruise Information:

V=85; %m/s
ro=0.653553306; %kg/m^3 
q=0.5*ro*V^2; %N/m^2

%% Aircraft Coefficients:

% Longitudinal
CL=0.149;            CD=0.022;          CLa=5.5;       
Cma=-0.24;          CLa_dot=4.2;        Cma_dot=-9.6;      
Cmq=-17.7;          CLM=0;              CDM=0;                
Cl_trim_e=0.38;     Cm_trim_e=-0.88;    CmM=0;
CLq=10;            CDa=0.12;           

% Lateral
Cyb=-1;          Clb=-0.11;          Cnb=0.17;       
Cnp=-0.09;         Clr=0.28;           Cnr=-0.26;          

Cn_trim_a=-0.003;    Cy_trim_r=0.028;     Cl_trim_r=0.05;   
Cn_trim_r=-0.12;   Clp=-0.39;          Cl_trim_a=0.1;
Cyp=-0.14;

%% Longitudinal Derivatives:

Xu=-(0+2*CD)*q*S/(m*V);               Xw=-(CDa-CL)*q*S/(m*V);
Zu=-(0+2*CL)*q*S/(m*V);               Zw=-(CLa+CD)*q*S/(m*V);
Zw_dot=CLa_dot*c*q*S/(2*V*V*m);       Za=Zw*V;
Za_dot=Zw_dot*V;                      Zq=CLq*c*q*S/(m*2*V);
Z_trim_e=Cl_trim_e*q*S/m;

Mq=Cmq*S*q*c/(V*Iy);      Mu=0;
Mw=Cma*S*q*c/(V*Iy);      Mw_dot=Cma_dot*S*q*c*c/(2*V*V*Iy);
Ma=V*Mw;                  Ma_dot=V*Mw_dot;
M_trim_e=Cm_trim_e*S*q*c/Iy;

A_Long_F=[ Xu            Xw            0            -9.81;
         Zu            Zw            V            0;
         Mu+Mw_dot*Zu  Mw+Mw_dot*Zw  Mq+Mw_dot*V  0;
         0             0             1            0];

Z_trim_e_2=Z_trim_e/(V-Za_dot);
X_trim_e=0;
M_trim_e_2=Ma_dot*Z_trim_e_2+M_trim_e;

B_Long_F=[ Z_trim_e;
         X_trim_e;
         M_trim_e;
         0];
     
%% Lateral Derivatives:

Yb=q*S*Cyb/m;             Yp=q*S*b*Cyp/(2*m*V);
Yr=0;                     Lb=q*S*b*Clb/Ix;
Nb=q*S*b*Cnb/Iz;          Nr=q*S*(b^2)*Cnr/(2*Iz*V);
Lp=Clp*q*S*(b^2)/(2*Ix*V);
Lr=Clr*q*S*(b^2)/(2*V*Ix);
Np=q*S*(b^2)*Cnp/(2*Ix*V);

A_Lat_F=[ Yb/V        Yp/V            (Yr/V)-1       9.81/V;
        Lb          Lp              Lr             0;
        Nb          Np              Nr             0;
        0           1               0              0];

Y_trim_r=q*S*Cy_trim_r/m;
L_trim_a=q*S*b*Cl_trim_a/Ix;
L_trim_r=q*S*b*Cl_trim_r/Ix;
N_trim_a=q*S*b*Cn_trim_a/Iz;
N_trim_r=q*S*b*Cn_trim_r/Iz;

B_Lat_F=[ 0           Y_trim_r/V;
        L_trim_a    L_trim_r;
        N_trim_a    N_trim_r;
        0           0 ];