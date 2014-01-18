

module body(){
	intersection() {
		linear_extrude(file = "rod_clamps_large.dxf", layer = "0",height =17,convexity = 16, $fn=100);
		translate([-10,0,0])rotate([90,0,90])linear_extrude(file = "rod_clamps_large.dxf", layer = "side",height =20,convexity = 16, $fn=100);
	}
}

rotate([0,0,0])body();