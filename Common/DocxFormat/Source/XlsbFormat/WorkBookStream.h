/*
 * (c) Copyright Ascensio System SIA 2010-2021
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#ifndef WORKBOOKSTREAM_H
#define WORKBOOKSTREAM_H


#include "../../../../DesktopEditor/common/Types.h"
#include "../Base/Types_32.h"
#include "../XlsxFormat/WritingElement.h"
#include <string>
#include <memory.h>
#include <iostream>
#include "../../../../ASCOfficeXlsFile2/source/XlsFormat/Logic/CompositeObject.h"
typedef BYTE *LPBYTE;

namespace XLSB
{
    class StreamCacheReader;

    class WorkBookStream;
    typedef std::shared_ptr<WorkBookStream>		WorkBookStreamPtr;

    class WorkBookStream: public XLS::CompositeObject
    {
        BASE_OBJECT_DEFINE_CLASS_NAME(WorkBookStream)
    public:
        WorkBookStream();
        virtual ~WorkBookStream();

        XLS::BaseObjectPtr clone();

        virtual const bool loadContent(XLS::BinProcessor& proc);

        static const XLS::ElementType type = XLS::typeWorkbookStreamObject;

		XLS::BaseObjectPtr               m_BrtBeginBook;
		XLS::BaseObjectPtr               m_BrtFileVersion;
		XLS::BaseObjectPtr               m_BrtFileSharingIso;
		XLS::BaseObjectPtr               m_BrtFileSharing;
		XLS::BaseObjectPtr               m_BrtBookProtectionIso;
		XLS::BaseObjectPtr               m_BrtBookProtection;
		XLS::BaseObjectPtr               m_BrtWbProp;
		XLS::BaseObjectPtr               m_ACABSPATH;
		XLS::BaseObjectPtr               m_BOOKVIEWS;
		XLS::BaseObjectPtr               m_BUNDLESHS;
		XLS::BaseObjectPtr               m_FNGROUP;
		XLS::BaseObjectPtr               m_EXTERNALS;
		XLS::BaseObjectPtr               m_BrtCalcProp;
		XLS::BaseObjectPtr               m_BrtOleSize;
		XLS::BaseObjectPtr               m_BrtWebOpt;
		XLS::BaseObjectPtr               m_BrtEndBook;

        std::vector<XLS::BaseObjectPtr>  m_arBrtName;
        std::vector<XLS::BaseObjectPtr>  m_arBrtUserBookView;
        std::vector<XLS::BaseObjectPtr>  m_arBrtFileRecover;

    };

}

#endif // WORKBOOKSTREAM_H

