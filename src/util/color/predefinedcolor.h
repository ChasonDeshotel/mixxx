#ifndef PREDEFINEDCOLOR_H
#define PREDEFINEDCOLOR_H

#include <QColor>

class PredefinedColor final {
  public:
    PredefinedColor(QColor defaultRepresentation, QString sName, QString sDisplayName, int iId);

    inline bool operator==(const PredefinedColor& other) const {
        return m_iId == other.m_iId;
    }

    inline bool operator!=(const PredefinedColor& other) const {
        return m_iId != other.m_iId;
    }

    // The QColor that is used by default to render this PredefinedColor.
    const QColor m_defaultRepresentation;
    // The name of the color used programatically, e.g. on skin files.
    const QString m_sName;
    // The name of the color used on UI.
    const QString m_sDisplayName;
    // An Id uniquely identifying this predefined color.
    const int m_iId;
    // The brightness of this color, calculated with Color::brightness(const QColor&)
    const int m_iBrightness;
};
typedef std::shared_ptr<const PredefinedColor> PredefinedColorPointer;

#endif /* PREDEFINEDCOLOR_H */
