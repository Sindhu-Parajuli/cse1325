#include <gtkmm.h>
#ifndef __MAINWIN_H
#define __MAINWIN_H


#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
void on_quit_click();              // Exit the game
        void on_view_peripheral_click();
        void on_view_desktop_click();
        void on_view_order_click();
        void on_view_customer_click();
        void on_insert_peripheral_click();
        void on_insert_desktop_click();
        void on_insert_order_click();
        void on_insert_customer_click();
        void on_about_click();           // Display About dialog

    
        private:
        
        Store *store;
        Gtk::Label *data;
        Gtk::Label *msg;
};
#endif 
