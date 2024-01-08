#include "data.h"
#include "process.h"

int main() {
    // testing data.c
    // create_file("hola.txt");
    
    struct finfo ***list = malloc(sizeof(struct finfo **));
    int size = get_file_listing(".", list);
    for (int i = 0; i < size; i++) {
        printf("name: %s, size: %ld", (*list)[i]->entry->d_name, (*list[i])->stat_buffer->st_size);
    }    

    display_dir("/home/naowal/Documents");
    
}
