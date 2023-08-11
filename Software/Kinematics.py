

from sympy import *
import numpy as np

q1, q2, q3, q4, q5, q6, q7 = symbols('q1:8')
d1, d2, d3, d4, d5, d6, d7 = symbols('d1:8')
a0, a1, a2, a3, a4, a5, a6 = symbols('a0:7')
alpha0, alpha1, alpha2, alpha3, alpha4, alpha5 , alpha6 = symbols('alpha0:7')






s = {alpha0:     0,  a0:     0,  d1:   0.75,
     alpha1: -pi/2,  a1:  0.35,  d2:      0, q2:  q2-pi/2,
     alpha2:     0,  a2:  1.25,  d3:      0,
     alpha3: -pi/2,  a3:-0.054,  d4:    1.5,
     alpha4:  pi/2,  a4:     0,  d5:      0,
     alpha5: -pi/2,  a5:     0,  d6:      0,
     alpha6:     0,  a6:     0,  d7:  0.303, q7:     0}
     
     



def matrix(alpha, a, d, q):
    answer = Matrix([[             cos(q),            -sin(q),            0,              a],
                     [  sin(q)*cos(alpha),  cos(q)*cos(alpha),  -sin(alpha),  -sin(alpha)*d],
                     [  sin(q)*sin(alpha),  cos(q)*sin(alpha),   cos(alpha),   cos(alpha)*d],
                     [                  0,                  0,            0,              1]])
    return answer

  
T0_1 = matrix(alpha=alpha0, a=a0, d=d1, q=q1)
T1_2 = matrix(alpha=alpha1, a=a1, d=d2, q=q2)
T2_3 = matrix(alpha=alpha2, a=a2, d=d3, q=q3)
T3_4 = matrix(alpha=alpha3, a=a3, d=d4, q=q4)
T4_5 = matrix(alpha=alpha4, a=a4, d=d5, q=q5)
T5_6 = matrix(alpha=alpha5, a=a5, d=d6, q=q6)
T6_G = matrix(alpha=alpha6, a=a6, d=d7, q=q7)

T0_1 = T0_1.subs(s)
T1_2 = T1_2.subs(s)
T2_3 = T2_3.subs(s)
T3_4 = T3_4.subs(s)
T4_5 = T4_5.subs(s)
T5_6 = T5_6.subs(s)
T6_G = T6_G.subs(s)

# compinsation of homogeneous transform

T0_2 = simplify(T0_1 * T1_2)
T0_3 = simplify(T0_2 * T2_3)
T0_4 = simplify(T0_3 * T3_4)
T0_5 = simplify(T0_4 * T4_5)
T0_6 = simplify(T0_5 * T5_6)
T0_G = simplify(T0_6 * T6_G)


def rot_x(angle):
    R_x = Matrix([[   1,                0,               0,     0],
                [     0,       cos(angle),     -sin(angle),     0],
                [     0,       sin(angle),      cos(angle),     0],
                [     0,                0,               0,     1]])
    return R_x

def rot_y(angle):
    R_y = Matrix([[   cos(angle),                0,    sin(angle),     0],
                [             0,                1,             0,     0],
                [   -sin(angle),                0,    cos(angle),     0],
                [             0,                0,             0,     1]])
    return R_y

def rot_z(angle):
    R_z = Matrix([[      cos(angle),      -sin(angle),          0,      0],
                [       sin(angle),       cos(angle),          0,      0],
                [                0,                0,          1,      0],
                [                0,                0,          0,      1]])
    return R_z


R_corr= simplify(rot_z(np.pi) * rot_y(-np.pi/2))


T_total = simplify(T0_G * R_corr)
px=o
py=o
pz=o

EE_position = Matrix([[px],[py],[pz]])
R_EE = rot_z(yaw)[0:3,0:3] * rot_y(pitch)[0:3,0:3] * rot_x(roll)[0:3,0:3] *R_corr[0:3,0:3]

WC = EE_position - 0.303*R_EE[:,2]

theta_1 = atan2(WC[1],WC[0])



# for B
WX_new = sqrt(pow(WC[0],2) + pow(WC[1],2)) - 0.35
WZ_new = WC[2] - 0.75
branch_B = sqrt(pow(WZ_new,2) + pow(WX_new,2))

# for C and A
C = 1.25
A = 1.5

# for the other angles we need to calculate theta_2 and theta_3
angle_a = math.acos(( pow(branch_B,2) + pow(C,2) - pow(A,2) ) / ( 2 * branch_B * C ))
angle_Q = atan2(WZ_new,WX_new)
angle_b = math.acos((pow(C,2) + pow(A,2) - pow(branch_B,2)) / (2 * C * A))

#for theta_2 and theta_3
theta_2 = np.pi/2 - angle_a - angle_Q
theta_3 = np.pi/2 - angle_b - 0.03598

# the rotation matrix with respect to the base link
Rrpy = R_EE

R0_3 = T0_3.evalf(subs={q1: theta_1, q2: theta_2, q3: theta_3})[0:3,0:3]

R3_6 = R0_3.inv() * Rrpy

theta_4 = atan2(R3_6[2, 2], -R3_6[0, 2])
theta_5 = atan2(sqrt(R3_6[0, 2]*R3_6[0, 2]+R3_6[2, 2]*R3_6[2, 2]), R3_6[1, 2])
theta_6 = atan2(-R3_6[1, 1], R3_6[1, 0])








