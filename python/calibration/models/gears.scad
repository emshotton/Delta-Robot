body();




module body(){

	color([0.6,0.6,0.4])translate([0,0,0])linear_extrude(file = "gears.dxf", layer = "59_teeth",height =6,convexity = 10);

	color([0.6,0.4,0.6])translate([10,0,0])linear_extrude(file = "gears.dxf", layer = "11_teeth",height =6,convexity = 10);
}