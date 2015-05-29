/*
 * HexNumberGridEditor.h
 *
 *  Created on: 29 May 2015
 *      Author: podonoghue
 */

#ifndef SRC_HEXNUMBERGRIDEDITOR_H_
#define SRC_HEXNUMBERGRIDEDITOR_H_

#include <wx/grid.h>
#include <wx/valtext.h>
#include <wx/textctrl.h>

//#include <wx/generic/grideditors.h>

class HexNumberGridEditor: public wxGridCellTextEditor {
public:
   HexNumberGridEditor() {};

   virtual ~HexNumberGridEditor() {};

   virtual void Create(wxWindow* parent, wxWindowID id, wxEvtHandler* evtHandler) {
      wxArrayString includeList;
      includeList.Add(wxT("0"));
      includeList.Add(wxT("1"));
      includeList.Add(wxT("2"));
      includeList.Add(wxT("3"));
      includeList.Add(wxT("4"));
      includeList.Add(wxT("5"));
      includeList.Add(wxT("6"));
      includeList.Add(wxT("7"));
      includeList.Add(wxT("8"));
      includeList.Add(wxT("9"));
      includeList.Add(wxT("a"));
      includeList.Add(wxT("b"));
      includeList.Add(wxT("c"));
      includeList.Add(wxT("d"));
      includeList.Add(wxT("e"));
      includeList.Add(wxT("f"));
      includeList.Add(wxT("A"));
      includeList.Add(wxT("B"));
      includeList.Add(wxT("C"));
      includeList.Add(wxT("D"));
      includeList.Add(wxT("E"));
      includeList.Add(wxT("F"));

      wxTextValidator textValidator(wxFILTER_INCLUDE_CHAR_LIST);
      textValidator.SetIncludes(includeList);

      wxGridCellTextEditor::Create(parent,id, evtHandler);
      ((wxTextCtrl *)this->GetControl())->SetValidator( textValidator);
   }
};

#endif /* SRC_HEXNUMBERGRIDEDITOR_H_ */
