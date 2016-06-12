#ifndef UTILS_H
#define UTILS_H

#include <QByteArray>
#include <QVariantMap>

namespace utils {

template <typename T>
QString toString(const T& in)
{
    return std::to_string(in).c_str();
}

// convert json to varian map
// throws exception
QVariantMap convertJson(const QByteArray& data);

}

#endif // UTILS_H