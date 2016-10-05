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


void read_scene(char* filename, buffer) {
  int c;
  FILE* json = fopen(filename, "r");

  if (json == NULL) {
    fprintf(stderr, "Error: Could not open file \"%s\"\n", filename);
    exit(1);
  }
  
  skip_ws(json);
  
  // Find the beginning of the list
  expect_c(json, '[');

  skip_ws(json);

  // Find the objects

  while (1) {
    c = fgetc(json);
    if (c == ']') {
      fprintf(stderr, "Error: This is the worst scene file EVER.\n");
      fclose(json);
      return;
    }
    if (c == '{') {
      skip_ws(json);
    
      // Parse the object
      char* key = next_string(json);
      if (strcmp(key, "type") != 0) {
	fprintf(stderr, "Error: Expected \"type\" key on line number %d.\n", line);
	exit(1);
      }

      skip_ws(json);

      expect_c(json, ':');

      skip_ws(json);

      char* value = next_string(json);

      if (strcmp(value, "camera") == 0) {
      } else if (strcmp(value, "sphere") == 0) {
      } else if (strcmp(value, "plane") == 0) {
      } else {
	fprintf(stderr, "Error: Unknown type, \"%s\", on line number %d.\n", value, line);
	exit(1);
      }

      skip_ws(json);

      while (1) {
	// , }
	c = next_c(json);
	if (c == '}') {
	  // stop parsing this object
	  break;
	} else if (c == ',') {
	  // read another field
	  skip_ws(json);
	  char* key = next_string(json);
	  skip_ws(json);
	  expect_c(json, ':');
	  skip_ws(json);
	  if ((strcmp(key, "width") == 0) ||
	      (strcmp(key, "height") == 0) ||
	      (strcmp(key, "radius") == 0)) {
	    double value = next_number(json);
	  } else if ((strcmp(key, "color") == 0) ||
		     (strcmp(key, "position") == 0) ||
		     (strcmp(key, "normal") == 0)) {
	    double* value = next_vector(json);
	  } else {
	    fprintf(stderr, "Error: Unknown property, \"%s\", on line %d.\n",
		    key, line);
	    //char* value = next_string(json);
	  }
	  skip_ws(json);
	} else {
	  fprintf(stderr, "Error: Unexpected value on line %d\n", line);
	  exit(1);
	}
      }
      skip_ws(json);
      c = next_c(json);
      if (c == ',') {
	// noop
	skip_ws(json);
      } else if (c == ']') {
	fclose(json);
	return;
      } else {
	fprintf(stderr, "Error: Expecting ',' or ']' on line %d.\n", line);
	exit(1);
      }
    }
  }
  fclose(FILE);
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

    
A = Xd^2 + Yd^2 + Zd^2
B = 2 * (Xd * (X0 - Xc) + Yd * (Y0 - Yc) + Zd * (Z0 - Zc))
C = (X0 - Xc)^2 + (Y0 - Yc)^2 + (Z0 - Zc)^2 - Sr^2

t0, t1 = (- B + (B^2 - 4*C)^1/2) / 2


    
    
    


void write_p3(Pixel* buffer, int width, int height, char* filename) {
      FILE* fh = fopen(filename, "w");
      fprintf("P3 %d %d 255 ");
      for ( int i=0; i<w*h; i+=1) {
            fprintf("%d %d %d ", buffer[i].r, buffer[i].g, buffer[i].b);
      }
      fclose(fh);


}






