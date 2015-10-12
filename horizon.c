#define _GNU_SOURCE
#include <dlfcn.h>
#include <gdk/gdkkeysyms.h>
#include <gdk/gdk.h>
typedef void (*orig_gtk_main_do_event)(GdkEvent *event);

void gtk_main_do_event(GdkEvent* event){
    if(event->type == GDK_KEY_PRESS || event->type == GDK_KEY_RELEASE){
	//the hardware 
	GdkEventKey* event_key = (GdkEventKey*) event;
	event_key->hardware_keycode = 30;
	orig_gtk_main_do_event orig_func;
	orig_func = (orig_gtk_main_do_event) dlsym(RTLD_NEXT, "gtk_main_do_event");
	
	orig_func((GdkEvent*)event_key);
	
    }else{
     orig_gtk_main_do_event orig_func;
    orig_func = (orig_gtk_main_do_event) dlsym(RTLD_NEXT, "gtk_main_do_event");
   
	orig_func(event);
    }
}
