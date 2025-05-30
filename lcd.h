void initlcd(void);
void writelcd(unsigned char dat);
void charlcd(unsigned char ascii);
void cmdlcd(unsigned char cmd);
void SetCursor(unsigned char lineNo,unsigned char pos);
void strlcd(unsigned char *str);
void u32lcd(unsigned int num);
