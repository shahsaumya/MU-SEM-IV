I ran these programs on Ubuntu using libgraph.
Hence, while runnning these on Windows make the following changes:
	1) change initgraph(&gd,&gm,NULL) to initgraph(&gd,&gm,"")
	2) make sure to add getch()
