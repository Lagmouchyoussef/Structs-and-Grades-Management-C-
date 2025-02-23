#include <stdio.h>

typedef struct {
    int width;    
    int length;   
    int thickness;  
    int wood_type;  
} Panel;

Panel input_panel() {
    Panel p;
    printf("Enter width (in mm): ");
    scanf("%d", &p.width);
    printf("Enter length (in mm): ");
    scanf("%d", &p.length);
    printf("Enter thickness (in mm): ");
    scanf("%d", &p.thickness);
    printf("Enter wood type (0: pine, 1: oak, 2: beech): ");
    scanf("%d", &p.wood_type);
    return p;
}

void display_panel(Panel p) {
    char* wood_type_str;
    switch (p.wood_type) {
        case 0: wood_type_str = "pine"; break;
        case 1: wood_type_str = "oak"; break;
        case 2: wood_type_str = "beech"; break;
        default: wood_type_str = "unknown"; break;
    }
    printf("Wood panel:\n");
    printf("  Width: %d mm\n", p.width);
    printf("  Length: %d mm\n", p.length);
    printf("  Thickness: %d mm\n", p.thickness);
    printf("  Wood type: %s\n", wood_type_str);
}

double calculate_volume(Panel p) {
    double volume = (double)(p.width * p.length * p.thickness) / 1e9;
    return volume;
}

int main() {
    Panel p = input_panel();
    display_panel(p);
    double volume = calculate_volume(p);
    printf("Panel volume: %.6f m³\n", volume);
    return 0;
}