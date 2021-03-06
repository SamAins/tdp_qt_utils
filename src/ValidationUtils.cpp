#include "tdp_qt_utils/ValidationUtils.h"

#include <QSet>
#include <QRegExp>

namespace tdp_qt_utils
{

//##################################################################################################
bool validateEmail(const QString& text)
{
  static const QRegExp regExp("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");

  if(text.isEmpty())
    return false;

  return regExp.exactMatch(text.toUpper());
}

//##################################################################################################
bool validateAlpha(const QString& text)
{
  QByteArray t = text.toLatin1();

  for(const char* d = t.constData(); (*d)!=0; d++)
    if(!(((*d)>='a' && (*d)<='z') || ((*d)>='A' && (*d)<='Z')))
      return false;

  return true;
}


//##################################################################################################
bool validateAlphaNumeric(const QString& text)
{
  QByteArray t = text.toLatin1();

  for(const char* d = t.constData(); (*d)!=0; d++)
    if(!(((*d)>='a' && (*d)<='z') || ((*d)>='A' && (*d)<='Z') || ((*d)>='0' && (*d)<='9')))
      return false;

  return true;
}

}
