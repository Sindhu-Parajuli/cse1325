#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>
#include <sstream>
#include <fstream> // for std::cerr logging

Mainwin::Mainwin() : store{nullptr} {



    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("ELSA: YOUR OWN STORE");
    
    //<span size='24000' weight='bold' color = 'red'>ELSA:Things to know</span>

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
 // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

//Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New File", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);



//Append Open to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);


//Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

//Append Saveas to the File menu
    Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save as", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);



 //Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

//     VIEW
    // Create a view menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

//Append Customer,order,peripheral,desktop to the view menu
Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_customer);

Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_peripheral);

Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_desktop);

Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_order);


 //     Insert
    // Create a insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);


//Append Customer,order,peripheral,desktop to the insert menu
Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customers->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_customers);

Gtk::MenuItem *menuitem_peripherals = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_peripherals->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    Gtk::Menu *enu = Gtk::manage(new Gtk::Menu());
    menuitem_peripherals->set_submenu(*enu);
      
    //menuitem_insert->set_submenu(*insertmenu);
    insertmenu->append(*menuitem_peripherals);
   

Gtk::MenuItem *menuitem_pheral = Gtk::manage(new Gtk::MenuItem("_RAM", true));
    menuitem_pheral->signal_activate().connect([this] {this->on_ram_click();});
    enu->append(*menuitem_pheral);

Gtk::MenuItem *menuitem_periphera = Gtk::manage(new Gtk::MenuItem("_Other", true));
    menuitem_periphera->signal_activate().connect([this] {this->on_other_click();});
    enu->append(*menuitem_periphera);


Gtk::MenuItem *menuitem_desktops = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_desktops->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_desktops);

Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_orders->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_orders);


 //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
//           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);
 data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    data->set_text("Welcome to ELSA: Your own computer store!");


// EASTER
// Append Easter to the Help menu
	Gtk::MenuItem *menuitem_easter = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
	menuitem_easter->signal_activate().connect([this] {this->on_easter_egg_click();});
	helpmenu->append(*menuitem_easter);

//S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    vbox->show_all();
store = new Store();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_store_click() 
{
 
 store = new Store();
 
}

void Mainwin::on_save_as_click() {

Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);

auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

dialog.set_filename("untitled.elsa");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();
    

    
if (result == 1) 
	{
		filename = dialog.get_filename();
		on_save_click();
	}
    
}



void Mainwin::on_save_click() {

 try {
        std::ofstream ofs{filename};
        store->save(ofs);
    } catch (std::exception& e) {
        std::ostringstream oss;
        oss << "ERROR saving file\n" << e.what();
        Gtk::MessageDialog{*this, oss.str(), false, Gtk::MESSAGE_ERROR}.run();
    }

}

void Mainwin::on_open_click() {
Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

 auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

dialog.set_filename("untitled.elsa");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();
    
    if (result == 1) 
{


    filename = dialog.get_filename();
		try 
		{
			delete store;
			std::ifstream ifs{filename};
			store = new Store{ifs};
} catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open elsa"}.run();
        }


}
}


void Mainwin::on_insert_customer_click() {
Gtk::Dialog dialog{"Insert Customer", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);


    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

dialog.get_content_area()->add(grid);

    dialog.add_button("Insert",Gtk::RESPONSE_OK );
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    int response;

    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {

        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_phone.get_text().size() == 0) {e_phone.set_text("*required*"); continue;}
        if (e_email.get_text().size() == 0) {e_email.set_text("*required*"); continue;}


 Customer *me = new Customer{e_name.get_text(), e_phone.get_text(), e_email.get_text()};

    this->store->add_customer(*me);
     
     data->set_text(std::to_string(this->store->num_customers())+ "  "+ "Customer Added");
msg->set_text("New Customer Added!");
break;

}       
    
}

void Mainwin::on_insert_peripheral_click() {
/*
EntryDialog edialog{*this, "What's the part you want to buy?"};
	edialog.set_text("Type Name here");
	edialog.run();
	std::string name = edialog.get_text() + " ";

EntryDialog edialog2{*this, "Please enter cost of price" };
  edialog2.run();
  std::string newprice = edialog2.get_text();
  double price = std::stod(newprice);

Options *me = new Options(name,price);
     try {
                 this->store->add_option(*me);  
                } catch(std::exception& e) {
                    std::cerr << "#### INVALID OPTION ####\n\n";
                }
    
    
     
data->set_text("Number of peripherals added are " + std::to_string(this->store->num_options()));
msg->set_text("New Peripherals Added!");
*/    
}


void Mainwin::on_ram_click()
{

EntryDialog edialog{*this, "What's the part you want to buy?"};
	edialog.set_text("Type Name here");
	edialog.run();
	std::string name = edialog.get_text() + " ";


EntryDialog edialog2{*this, "Please enter cost of price" };
  edialog2.run();
  std::string newprice = edialog2.get_text();
  double price = std::stod(newprice);


EntryDialog edialog3{*this, "Please enter memory of RAM" };
  edialog3.run();
  std::string gbs = edialog3.get_text();
  int gb  = std::stoi(gbs);


Options *me = new Ram(name,price,gb);
     try {
                 this->store->add_option(*me);  
                } catch(std::exception& e) {
                    std::cerr << "#### INVALID OPTION ####\n\n";
                }
    
    
     
data->set_text("Number of peripherals added are " + std::to_string(this->store->num_options()));
msg->set_text("New Peripherals Added!");
   
}

void Mainwin::on_other_click()
{

EntryDialog edialog{*this, "What's the part you want to buy?"};
	edialog.set_text("Type Name here");
	edialog.run();
	std::string name = edialog.get_text() + " ";

EntryDialog edialog2{*this, "Please enter cost of price" };
  edialog2.run();
  std::string newprice = edialog2.get_text();
  double price = std::stod(newprice);

Options *me = new Options(name,price);
     try {
                 this->store->add_option(*me);  
                } catch(std::exception& e) {
                    std::cerr << "#### INVALID OPTION ####\n\n";
                }
    
    
     
data->set_text("Number of peripherals added are " + std::to_string(this->store->num_options()));
msg->set_text("New Peripherals Added!");
   

}

	
void Mainwin::on_insert_desktop_click() {

std::string name = " ";
int desktop = store->new_desktop();
             std::ostringstream oss;
            while(true) {
                oss <<  store->desktop(desktop) << "\n";

for(int i=0; i<store->num_options(); ++i) 
                oss << i << " ) " << store->option(i) << "\n";
               //std::cout << i << ") " << store.option(i) << '\n';
               name = name + "  " + oss.str() + "\n";

 EntryDialog edialog{*this, "Add which peripheral (-1 when done?)"};
                	edialog.set_text("option");
	                edialog.run();
	                std::string optionss = edialog.get_text();
                        int option = std::stoi(optionss);


if(option == -1) break;
                try {
                    store->add_option(option, desktop);
                } catch(std::exception& e) {
                    std::cerr << "#### INVALID OPTION ####\n\n";
                }
                
                msg->set_text("Listed Desktop");
                data->set_text(name);
}
}

void Mainwin::on_insert_order_click() {
std::string name = " ";
//std::string names = " ";
std::ostringstream oss;
//std::ostringstream osss;
for(int i=0; i<store->num_customers(); ++i) 

                oss << i << ") " << store->customer(i) << '\n';
                name = name + "  " + oss.str() + "\n";
EntryDialog edialog{*this, "Select Customer"};
                	edialog.set_text("customer");
	                edialog.run();
	                std::string customerss = edialog.get_text();
                        int customer = std::stoi(customerss);

 int order = store->new_order(customer);

                while(true) {
                for(int i=0; i<store->num_desktops(); ++i) 
                    oss << i << ") " << store->desktop(i) << '\n';
                    name = name + "  " + oss.str() + "\n";
                    EntryDialog edialog{*this, "Select Desktop enter -1 when done"};
                	edialog.set_text("desktop");
edialog.run();
	                std::string desktopss = edialog.get_text();
                        int desktop = std::stoi(desktopss);
                    
                if(desktop == -1) break;

                try {
                 store->add_desktop(desktop, order);
                } catch(std::exception& e) {
                    std::cerr << "#### INVALID OPTION ####\n\n";
                }

                

            
             msg->set_text("Listed Order");
             //data->set_text(name);
           

}
}

void Mainwin::on_about_click() {

Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
    auto logo = Gdk::Pixbuf::create_from_file("elsa.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Sindhu Parajuli"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Sindhu Parajuli @freelogodesign.org"
        };
    dialog.set_artists(artists);
    dialog.run();

}

// COMBINED observer / callback
void Mainwin::on_view_peripheral_click() {

std::string name = "Here's a list of your Peripherals and cost\n";

for(int i=0; i<store->num_options(); ++i) {
   std::ostringstream oss;
   oss << i << " ) " << store->option(i) << "\n";
   
   name = name + "  " + oss.str() + "\n";
   //msg->set_text("Listed Peripherals");
   data->set_text(name);
     }
	
    
}

void Mainwin::on_view_desktop_click() {

std::string name = "Here's a list of your chosen Desktop with peripherals\n";

for(int i=0; i<store->num_desktops(); ++i) {
   std::ostringstream oss;
   oss << i << " ) " << store->desktop(i) << "\n";
   
   name = name + "  " + oss.str() + "\n";
   msg->set_text("Listed Desktops");
   data->set_text(name);
     }


 
}

void Mainwin::on_view_order_click() {
std::string name = "Here's your Order and cost\n";

for(int i=0; i<store->num_orders(); ++i) {
   std::ostringstream oss;
   oss << i << " ) " << store->order(i) << "\n";
   
   name = name + "  " + oss.str() + "\n";
   //msg->set_text("Listed Peripherals");
   data->set_text(name);
     } 
}

void Mainwin::on_view_customer_click() {
std::string name = "Here's a list of your Customers in order of name, phone and email\n";

for(int i=0; i<store->num_customers(); ++i) {
   std::ostringstream oss;
   oss << "\n" << i << " ) " << store->customer(i) << "\n";
   //std::cout << i << " ) " << store.customer(i) << "\n";
   name = name + "  " + oss.str() + "\n";
   //msg->set_text("Listed Customers");
   data->set_text(name);
     }
	
}

void Mainwin::on_easter_egg_click() {
    Customer c{"Bugs Bunny", "817-ACA-RROT", "bugs@loony.tunes"};          store->add_customer(c);
    c = Customer{"Elastigirl", "817-STR-ETCH", "helen@incredibles.movie"}; store->add_customer(c);
    c = Customer{"Tuck and Roll", "817-UFI-RED2", "circus@bugs.life"};     store->add_customer(c);
    c = Customer{"Tiana", "817-NOG-RIMM", "princess@lily.pad"};            store->add_customer(c);

    Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
    o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
    o = Options{"CPU: 300 MHz AM3351BZCEA30R ARM", 11.03}; store->add_option(o);
    o = Options{"CPU: 240 MHz ColdFire MCF5", 17.33};      store->add_option(o);


    o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
    o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
    o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
    o = Options{"16 GB RAM", 92.99};                       store->add_option(o);
    o = Options{"32 GB RAM", 134.96};                      store->add_option(o);
    o = Options{"64 GB RAM", 319.99};                      store->add_option(o);

    o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
    o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

    o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
    o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
    o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);

    int desktop = store->new_desktop();
    store->add_option(0, desktop);
    store->add_option(9, desktop);
    store->add_option(14, desktop);

    desktop = store->new_desktop();
    store->add_option(1, desktop);
    store->add_option(7, desktop);
    store->add_option(17, desktop);

    desktop = store->new_desktop();
    store->add_option(5, desktop);
    store->add_option(7, desktop);
    store->add_option(15, desktop);

}






void Mainwin::on_quit_click() {
    close();
}



