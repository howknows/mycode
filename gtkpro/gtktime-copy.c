#include <gtk/gtk.h>
	 
	#include <time.h>
	 
	#include <glib.h>
	 
	GtkWidget * label;
	 
	 
	time_t times;
	 
	gint settime(gpointer data)
	{  
	 
	    times=time(NULL);
	 
 
	    gtk_label_set_text(GTK_LABEL(label),ctime(&times));
 
	 
	    return TRUE;
	 
	}
	 
	 
	int main(int argc,char* argv[])
	{
	 
	    GtkWidget* window;
	 
	  
	 
	    GtkBuilder* builder;
	 
	  
	 
	    gtk_init(&argc,&argv);
	 
	 
	    builder=gtk_builder_new();
	 
	 
	    gtk_builder_add_from_file(builder,"time.glade",NULL);
	 
 
	    window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
	 
	 
	    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	 
	    label=GTK_WIDGET(gtk_builder_get_object(builder,"label1"));
	 
	 
	    g_object_unref(G_OBJECT(builder));
	     
	 
	    gint s=g_timeout_add(1000,settime,NULL);
	 
	 
	     gtk_widget_show(label);
	 
	 
	    gtk_widget_show(window);
	 
	 
	    gtk_main();
	 
	 
	    return 0;	 
	}