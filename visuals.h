#ifndef VISUALS_H_INCLUDED
#define VISUALS_H_INCLUDED

int DisplayPicture(struct Picture * pic,float x,float y,float z,float heading,float pitch,float roll);
void DisplayHUD();
void MainDisplayFunction();
void DrawBackground();
int DrawEffects();


int MinPictureThatIsVisible();
int MaxPictureThatIsVisible();

void InitEffects();

extern unsigned int ENABLE_WIGGLING;
#endif // VISUALS_H_INCLUDED
