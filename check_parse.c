#include "rt_minirt.h"

void	check_parse_data(t_rt_info info)
{
	printf("amb ratio: %f\n", info.amb.amb_ratio);
	printf("amb color r: %f\n", info.amb.color.r);
	printf("amb color g: %f\n", info.amb.color.g);
	printf("amb color b: %f\n", info.amb.color.b);
	printf("cam focal length: %f\n", info.cam.focal_len);
	printf("cam horizontal x: %f\n", info.cam.horizontal.x);
	printf("cam horizontal y: %f\n", info.cam.horizontal.y);
	printf("cam horizontal z: %f\n", info.cam.horizontal.x);
	printf("cam left bottom x: %f\n", info.cam.left_bottom.x);
	printf("cam left bottom y: %f\n", info.cam.left_bottom.y);
	printf("cam left bottom z: %f\n", info.cam.left_bottom.z);
	printf("cam origin x: %f\n", info.cam.orig.x);
	printf("cam origin y: %f\n", info.cam.orig.y);
	printf("cam origin z: %f\n", info.cam.orig.z);
	printf("cam vertical x: %f\n", info.cam.vertical.x);
	printf("cam vertical y: %f\n", info.cam.vertical.y);
	printf("cam vertical z: %f\n", info.cam.vertical.z);
	printf("cam viewpoint width: %f\n", info.cam.viewport_w);
	printf("cam viewpoint height: %f\n", info.cam.viewport_h);
	printf("light brightness: %f\n", info.light.bright);
	printf("light color r: %f\n", info.light.color.r);
	printf("light color g: %f\n", info.light.color.g);
	printf("light color b: %f\n", info.light.color.b);
	printf("light origin x: %f\n", info.light.orig.y);
	printf("light origin y: %f\n", info.light.orig.z);
	printf("light origin z: %f\n", info.light.orig.x);
	int	i = 0;
	t_obj *object = info.obj.head;
	char *id;
	while (object)
	{
		if (object->identifier == PLANE)
			id = "Plane";
		if (object->identifier == SPHERE)
			id = "Sphere";
		if (object->identifier == CYLINDER)
			id = "Cylinder";
		printf("%s %f\n", id, object->center.x);
		printf("%s %f\n", id, object->center.y);
		printf("%s %f\n", id, object->center.z);
		printf("%s %f\n", id, object->color.r);
		printf("%s %f\n", id, object->color.g);
		printf("%s %f\n", id, object->color.b);
		printf("%s %f\n", id, object->vector.x);
		printf("%s %f\n", id, object->vector.y);
		printf("%s %f\n", id, object->vector.z);
		printf("%s %f\n", id, object->diameter);
		printf("%s %f\n", id, object->height);
		object = object->next;
	}
}