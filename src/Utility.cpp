/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2006 Pawel Stolowski <pawel.stolowski@wp.pl>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#include "Utility.h"
#include <QStringList>
#include <QFileInfo>
#include <stdlib.h>
#include <utime.h>

QString Utility::which(const QString &command)
{
	const QString paths = QString(getenv("PATH"));
	QStringList plist = paths.split(":");
	for (QStringList::const_iterator it = plist.begin(); it != plist.end(); it++)
	{
		QFileInfo finfo(*it + "/" + command);
		if (finfo.isExecutable())
			return finfo.absoluteFilePath();
	}
	return QString::null;
}

void Utility::touch(const QString &fname)
{
    utime(fname.toLocal8Bit(), NULL);
}
