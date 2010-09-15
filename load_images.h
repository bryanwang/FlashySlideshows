#ifndef LOAD_IMAGES_H_INCLUDED
#define LOAD_IMAGES_H_INCLUDED

#include <GL/glu.h>


#define OVERFLOW_GUARD_BYTES 10101001

struct Position3D
{
  char ok;
  float x,y,z;
  float heading,yaw,pitch;
  float size_x,size_y;
};

struct Picture
{


  unsigned int height;
  unsigned int width;
  unsigned int depth;
  float transparency; /* 0.0 -> 1.0 */

  unsigned int time_viewed;
  unsigned int times_viewed;

  unsigned int failed_to_load;
  unsigned char thumbnail_texture_loaded;
  unsigned char texture_loaded;

 // unsigned int ready_for_texture; /* Will be replaced with marked_for_texture_loading*/

  unsigned char marked_for_texture_loading;
  unsigned char marked_for_texture_removal;
  unsigned char marked_for_rgbdata_loading;
  unsigned char marked_for_rgbdata_removal;

  GLuint gl_rgb_texture;
  GLuint gl_rgb_thumbnail_texture;

  struct Position3D position;

  char filename[512];
  char ppm_filename[512];

  unsigned long rgb_data_size;
  char * rgb_data;
  unsigned long overflow_guard;

};

extern struct Picture *star;
extern struct Picture *heart;
extern struct Picture *loading;
extern struct Picture *loading_texture;
extern struct Picture *failed;
extern struct Picture *background;
extern struct Picture *picture_frame;

extern int OpenGL_is_rendering;
extern int OpenGL_is_making_textures;

int PictureCreationPending(struct Picture * picturedata);
int PictureLoadingPending(struct Picture * picturedata);

struct Picture * CreatePicture(char * filename,unsigned int force_load);
int LoadPicture(char * filename,struct Picture * pic);
int UnLoadPicture(struct Picture * pic);
int DestroyPicture(struct Picture * pic);

int PositionPicture(struct Picture * pic,unsigned int place);
#endif // LOAD_IMAGES_H_INCLUDED
