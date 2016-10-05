#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct {
  int kind; // 0 = camera, 1 = sphere, 2 = plane
  double color[3];
  union {
    struct {
      double center[3];
      double width;
      double hiehgt;
    } camera;
    struct {
      double center[3];
      double radius;
    } sphere;
    struct {
      double center[3];
      double normal;
    } plane;
  };
} Object;



void skip_ws(FILE* json){
    int c = fgetc(json);
    while(isspace(c)){
        c = fgetc(json);}
        ungetc(c, json);
}

int main(){
    FILE* json = fopen("input.json", "r");
    skip_ws(json);
    int c = fgetc(json);
    if (c! = '[') {
        fprintf(stderr, "Error: File must begin with list");
        fclose(json);
        exit(1)
    }
    skip_ws(json);
    
    c = fgetc(json);
    fclose(json);
    exit(o);
    }

}



void write_p3(Pixel* buffer, int width, int height, char* filename) {
      FILE* fh = fopen(filename, "w");
      fprintf("P3 %d %d 255 ");
      for ( int i=0; i<w*h; i+=1) {
            fprintf("%d %d %d ", buffer[i].r, buffer[i].g, buffer[i].b);
      }
      fclose(fh);


}





}
