#include<stdio.h>
#include<gtk/gtk.h>

void jia(GtkWidget *widget,gpointer label)
{
	
}

GdkPixbuf *create_pic(const gchar *filename)
{
	GdkPixbuf *pic;
	GError *error = NULL;
	pic = gdk_pixbuf_new_from_file(filename,&error);
	if(!pic){
		printf( "%s\n",error->message );
		g_error_free(error);
	}
	return pic;
}


void main(int argc,char **argv)
{
	GtkWidget *window;
	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Hello");
	gtk_window_set_default_size(GTK_WINDOW(window),230,150);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_icon(GTK_WINDOW(window),create_pic("icon.jpg"));
	gtk_widget_show(window);
	g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_main();
}