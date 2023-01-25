 #include <stdio.h>
    int main () { 
      FILE *fp;
      int c;
      fp = fopen("file.txt","w+");
      fputs("This is study.com", fp);
     
      fseek( fp, 7, SEEK_SET );
     
   
      fputs(" C Programming", fp);
     
   
      printf("The current position of the file pointer is: %ld\n", ftell(fp));
   
      rewind(fp);
    
      printf("The current position of the file pointer is: %ld\n", ftell(fp));
      while(1) { 
       c = fgetc(fp);
       if( feof(fp) ) { 
        break;
       }
       printf("%c", c);
      }
      fclose(fp);
      return(0);
    }

