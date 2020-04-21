#include <gtkmm.h>
#ifndef __MAINWIN_H
#define __MAINWIN_H


#include "store.h"
#include "Cpu.h"
#include "Disk.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:

void on_new_store_click();
void on_quit_click();

void on_save_as_click();

void on_save_click();

void on_open_click();
              // Exit the game
        void on_view_peripheral_click();
        void on_view_desktop_click();
        void on_view_order_click();
        void on_view_customer_click();
        void on_insert_peripheral_click();
        void on_insert_desktop_click();
        void on_insert_order_click();
        void on_insert_customer_click();
        void on_easter_egg_click();
        void on_about_click();           // Display About dialog
        void on_ram_click();
        void on_other_click();
        void on_cpu_click();
        void on_disk_click();
    
        private:
        
        Store *store;
        Gtk::Label *data;
        Gtk::Label *msg;
        std::string filename = "untitled.elsa";
        
};
#endif 
