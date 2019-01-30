#ifndef COLOR_H
#define COLOR_H

#include <QColor>
#include <QObject>

#include "util/color/predefinedcolor.h"
#include "util/color/predefinedcolormap.h"

// This class defines a set of predefined colors and provides some handy functions to work with them.
// A single global instance is create in the Color namespace.
// This class is thread-safe because all its methods and public properties are const.
class PredefinedColorSet final {
  public:
    const PredefinedColorPointer noColor = std::make_shared<PredefinedColor>(
        QColor(),
        QLatin1String("No Color"),
        QObject::tr("No Color"),
        0
    );
    const PredefinedColorPointer red = std::make_shared<PredefinedColor>(
        QColor("#E6194B"),
        QLatin1String("Red"),
        QObject::tr("Red"),
        1
    );
    const PredefinedColorPointer green = std::make_shared<PredefinedColor>(
        QColor("#3CB44B"),
        QLatin1String("Green"),
        QObject::tr("Green"),
        2
    );
    const PredefinedColorPointer yellow = std::make_shared<PredefinedColor>(
        QColor("#FFE119"),
        QLatin1String("Yellow"),
        QObject::tr("Yellow"),
        3
    );
    const PredefinedColorPointer blue = std::make_shared<PredefinedColor>(
        QColor("#4363D8"),
        QLatin1String("Blue"),
        QObject::tr("Blue"),
        4
    );
    const PredefinedColorPointer cyan = std::make_shared<PredefinedColor>(
        QColor("#42D4F4"),
        QLatin1String("Cyan"),
        QObject::tr("Cyan"),
        5
    );
    const PredefinedColorPointer magenta = std::make_shared<PredefinedColor>(
        QColor("#F032E6"),
        QLatin1String("Magenta"),
        QObject::tr("Magenta"),
        6
    );
    const PredefinedColorPointer pink = std::make_shared<PredefinedColor>(
        QColor("#FABEBE"),
        QLatin1String("Pink"),
        QObject::tr("Pink"),
        7
    );
    const PredefinedColorPointer teal = std::make_shared<PredefinedColor>(
        QColor("#469990"),
        QLatin1String("Teal"),
        QObject::tr("Teal"),
        8
    );
    const PredefinedColorPointer grey = std::make_shared<PredefinedColor>(
        QColor("#A9A9A9"),
        QLatin1String("Grey"),
        QObject::tr("Grey"),
        9
    );

    // The list of the predefined colors.
    const QList<PredefinedColorPointer> allColors {
        noColor,
        red,
        green,
        yellow,
        blue,
        cyan,
        magenta,
        pink,
        teal,
        grey,
    };

    PredefinedColorSet()
        : m_predefinedColorsNames(), m_defaultMap() {

        for (PredefinedColorPointer color : allColors) {
            m_predefinedColorsNames << color->m_sName;
            m_defaultMap.setRepresentation(color, color->m_defaultRepresentation);
        }
    }

    // A list with the names of the predefined colors.
    QList<QString> predefinedColorNames() const { return m_predefinedColorsNames; };

    // Returns the position of a PredefinedColor in the allColors list.
    int predefinedColorIndex(PredefinedColorPointer searchedColor) const {
        int position = 0;
        for (PredefinedColorPointer color : allColors) {
            if (*color == *searchedColor) {
                return position;
            }
            position++;
        }
        return 0;
    };

    // Return a predefined color from its name.
    // Return noColor if there's no color with such name.
    PredefinedColorPointer predefinedColorFromName(QString name) const {
        for (PredefinedColorPointer color : allColors) {
            if (color->m_sName == name) {
                return color;
            }
        }
        return noColor;
    };

    // Return a predefined color from its id.
    // Return noColor if there's no color with iId.
    PredefinedColorPointer predefinedColorFromId(int iId) const {
        for (PredefinedColorPointer color : allColors) {
            if (color->m_iId == iId) {
                return color;
            }
        }
        return noColor;
    };

    // The default color map, i.e. maps each predefined color to its default representation.
    PredefinedColorMap defaultMap() const { return m_defaultMap; };

  private:
    QList<QString> m_predefinedColorsNames;
    PredefinedColorMap m_defaultMap;
};
#endif /* COLOR_H */
