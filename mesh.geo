algebraic3d
solid box1 = plane(0, 0, 0; 0, 0, -4) -bc = 10;
solid box2 = plane(0, 0, 0; 0, -4, 0) -bc = 10;
solid box3 = plane(0, 0, 0; -4, 0, 0) -bc = 10;
solid box4 = plane(4, 4, 4; 4, 0, 0) -bc = 10;
solid box5 = plane(4, 4, 4; 0, 4, 0) -bc = 10;
solid box6 = plane(4, 4, 4; 0, 0, 4) -bc = 10;
solid box = box1 and box2 and box3 and box4 and box5 and box6;

solid cyl_1 = cylinder(0.258849, 0.686043, 0; 0.701651, 0.874457, 4; 0.25) -bc = 1;
solid cyl_2 = cylinder(0.974826, 2.36703, 0; 0.325674, 2.26014, 4; 0.25) -bc = 1;
solid cyl_3 = cylinder(0.506002, 3.14022, 0; 0.494498, 3.13362, 4; 0.25) -bc = 1;
solid cyl_4 = cylinder(2.2016, 0.54172, 0; 2.60556, 0.61878, 4; 0.25) -bc = 1;
solid cyl_5 = cylinder(2.15917, 2.41705, 0; 1.568, 2.35011, 4; 0.25) -bc = 1;
solid cyl_6 = cylinder(1.9192, 3.18474, 0; 1.86797, 2.88909, 4; 0.25) -bc = 1;
solid cyl_7 = cylinder(3.41342, 0.785429, 0; 3.04042, 1.17507, 4; 0.25) -bc = 1;
solid cyl_8 = cylinder(3.43114, 2.12973, 0; 3.60269, 2.19744, 4; 0.25) -bc = 1;
solid cyl_9 = cylinder(3.11528, 3.54501, 0; 3.27855, 3.58882, 4; 0.25) -bc = 1;
solid cyls = cyl_1 or cyl_2 or cyl_3 or cyl_4 or cyl_5 or cyl_6 or cyl_7 or cyl_8 or cyl_9;

solid matrix = box and not cyls;
solid obj = box and cyls;

tlo obj -col=[1,1,0];
tlo matrix -col=[0,0,1] -transparent;
