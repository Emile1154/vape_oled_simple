#include <controller/vape_controller.h>

#define LOOP for(;;)

int main() {
  init_vape();
  LOOP{
    vape_task();
  }
  return 0;
}