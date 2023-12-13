#include <stdio.h>
#include "vector/vector.h"
#include "view/view.h"
#include "figure/figure.h"

void    write_color(t_coord color)
{
    printf("%d %d %d\n", (int)(255.999 * color.x),
                        (int)(255.999 * color.y),
                        (int)(255.999 * color.z));
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
	t_sphere	sp;
    //Scene setting;
    canv = init_canvas(400, 300);
    cam = init_camera(&canv, vec(0, 0, 0));
	sp = sphere(vec(0, 0, -5), 2);
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
            pixel_color = ray_color(&ray, &sp);
        /* * * * 수정 끝 * * * */
            write_color(pixel_color);
            ++i;
        }
        --j;
    }
}