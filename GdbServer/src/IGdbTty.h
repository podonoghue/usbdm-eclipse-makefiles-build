/*
 * GdbTty.h
 *
 *  Created on: 18 Jul 2015
 *      Author: podonoghue
 */

#ifndef SRC_IGDBTTY_H_
#define SRC_IGDBTTY_H_

class IGdbTty {
public:
   enum {STD_IN, STD_OUT, STD_ERR};
protected:
   IGdbTty() {}
public:
   virtual ~IGdbTty() {};
   /**
    * Open input connection
    *
    * @return true => success
    */
   virtual bool     openInput()  { return true; };
   /**
    * Open output connection
    *
    * @return true => success
    */
   virtual bool     openOutput() { return true; };
   /**
    * Open error output connection
    *
    * @return true => success
    */
   virtual bool     openError() { return true; };
   /**
    * Check input connection
    *
    * @return true => success
    */
   virtual bool     isInputOpen()  { return true; };
   /**
    * Check output connection
    *
    * @return true => success
    */
   virtual bool     isOutputOpen() { return true; };
   /**
    * Check output connection
    *
    * @return true => success
    */
   virtual bool     isErrorOpen() { return true; };
   /**
    * Close input from console
    */
   virtual void     closeInput() {};
   /**
    * Close output to console
    */
   virtual void     closeOutput() {};
   /**
    * Close output to console
    */
   virtual void     closeError() {};
   /**
    * Close console
    */
   virtual void     closeAll() {};
   /**
    * Write character to console
    *
    * @param ch char to write
    */
   virtual void     putChar(int ch) = 0;
   /**
    * Get character from console
    *
    * @return character read (or EOF)
    */
   virtual int      getChar() = 0;
   /**
    * Write string to console
    *
    * @param s string to write
    */
   virtual void     puts(char *s) = 0;
   /**
    * Read string from console
    *
    * @param s    buffer for string
    * @param len  size of buffer
    *
    * @return number of characters read
    */
   virtual int      gets(char s[], int len) = 0;
};

#endif /* SRC_IGDBTTY_H_ */
