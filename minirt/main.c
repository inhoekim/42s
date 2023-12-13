#include <stdio.h>
#include "vector/vector.h"
#include "view/view.h"

typedef struct t_color3 {
	int x;
	int y;
	int z;
} t_color3;

void    write_color(t_vector pixel_color)
{
    printf("%d %d %d\n", (int)(255.999 * pixel_color.x),
                        (int)(255.999 * pixel_color.y),
                        (int)(255.999 * pixel_color.z));
}

int main(void)
{
    int         i;
    int         j;
    float      normalized_x;
    float      normalized_y;

    t_vector    pixel_color;
    /* * * * 수정 * * * */
    t_canvas    canv;
    t_camera    cam;
    t_ray       ray;

    //Scene setting;
    canv = init_canvas(800, 400);
    cam = init_camera(&canv, vec(0, 0, 0));
    /* * * * 수정 끝 * * * */

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    /* * * * 수정 * * * */
    printf("P3\n%d %d\n255\n", canv.width, canv.height);
    j = canv.height - 1;
    /* * * * 수정 끝 * * * */
    while (j >= 0)
    {
        i = 0;
        /* * * * 수정 * * * */
        while (i < canv.width)
        {
            normalized_x = (double)i / (canv.width - 1);
            normalized_y = (double)j / (canv.height - 1);
            //ray from camera origin to pixel
            ray = ray_primary(&cam, normalized_x, normalized_y);
            pixel_color = ray_color(&ray);
        /* * * * 수정 끝 * * * */
            write_color(pixel_color);
            ++i;
        }
        --j;
    }
}