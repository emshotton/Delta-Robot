
module petal(r){
	rotate([r,0,0])translate([0,0,10])
	difference(){
		sphere(r=10, $fn=10);
		translate([0,-10,-10])cube([10,20,20]);
		rotate([0,0,45])translate([-10,-10,-10])cube([10,20,20]);
		sphere(r=9.5, $fn=10);
	}
}

//time= $t;
//time=1.0/30.0*15;


angle = -90*sin(time*180);

rotate([0,0,time*90])translate([0,0,10])
sphere(r=sin(time*180)*5+5, $fn=10);

for (i=[0:7]){
		rotate([0,0,i*45.0 - time*180])
		translate([0,0.1,0])
		petal(angle);
}