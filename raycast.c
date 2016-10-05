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
      double height;
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

char* parse_string(FILE* json){
    char buffer[128];
    int c = fgetc(json);
    if (c!= '"'){
        fprintf(stderr, "Error: Expected string./n");
        exit(1);

    }
    c = fgetc(json);
    int i=0;
    while ( c!= '"'){
        buffer[i] = c;
        i += 1;
        c = fgetc(json);
    }
    buffer[1] = 0;
    return strdup(buffer);
    return buffer;
}
void skip_ws(FILE* json){
    int c = fgetc(json);
    while(isspace(c)){
        c = fgetc(json);}
        ungetc(c, json);
}
skip_ws(json);
char* type = parse_string(json);

if (strcmp(type, "camera") == 0) {
    else if(strcmp(type, "sphere") == 0){
        else if (strcmp(type, "plane") == 0) {
            else {
                fprintf(stderr, "Error: Unknown type");
                exit(1);
            }
        }
    }
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
    exit(0);
    }

skip_ws(json)
c = next_c(json);
if(c == '}'){
    break;
}
else if (c == ','){
    skip_ws(json);
    char* key = next_string(json);
    skip_ws(json);
    expect_c(json,':');
    skip_ws(json);
    if(strcmp(key, "width") == 0) || (strcmp(key,"height") == 0) || (strcmp(key,"radius") == 0){
        double value = next_number(json);}
        else{
            fprintf(stderr, "Error: Unknown property.";)}
            else{
                fprintf(stderr, "Error: Unexpected value on line %d\n", line);
                exit(1);
            }
        }
    }

double next_number(FILE* json){
double value;
fscanf(json, "%f", &value);
return value;}

double* next_vector(FILE* json){
    double* V = malloc(3*sizeof(double));
    v[0] = next_number(json);
    skip_ws(json);
    expect_c(json, ',');
    skip_ws(json);
    v[1]=next number(json);
    skip_ws(json);
    expect_c(json, ',');
    skip_ws(json);
    v[1] = next_number(json);}



void write_p3(Pixel* buffer, int width, int height, char* filename) {
      FILE* fh = fopen(filename, "w");
      fprintf("P3 %d %d 255 ");
      for ( int i=0; i<w*h; i+=1) {
            fprintf("%d %d %d ", buffer[i].r, buffer[i].g, buffer[i].b);
      }
      fclose(fh);


}






