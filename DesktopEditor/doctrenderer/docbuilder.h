﻿/*
 * (c) Copyright Ascensio System SIA 2010-2019
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
#ifndef DOCBUILDER_H
#define DOCBUILDER_H

#include "./common.h"

namespace NSDoctRenderer
{
	/**
	 * String class. With wchar_t* property.
	 */
	class CString_Private;
	class Q_DECL_EXPORT CString
	{
	public:
		CString();
		CString(const CString& src);
		CString& operator=(const CString& src);
		~CString();

		wchar_t* c_str() const;

	private:
		CString_Private* m_internal;
		friend class CDocBuilderValue;
	};

	/**
	 * Class for getting results of called js commands
	 * Represent the wrapper over js object
	 */
	class CDocBuilderValue_Private;
	class Q_DECL_EXPORT CDocBuilderValue
	{
	public:
		CDocBuilderValue();
		CDocBuilderValue(const CDocBuilderValue& src);
		CDocBuilderValue& operator=(const CDocBuilderValue& src);
		~CDocBuilderValue();
		void* private_get_internal();

	public:
		/**
		 * Returns true if this object is empty.
		 */
		bool IsEmpty();
		/**
		 * Clear object
		 */
		void Clear();

		/**
		 * Returns true if this object is null.
		 */
		bool IsNull();
		/**
		 * Returns true if this object is undefined.
		 */
		bool IsUndefined();
		/**
		 * Returns true if this object is boolean.
		 */
		bool IsBool();
		/**
		 * Returns true if this object is integer.
		 */
		bool IsInt();
		/**
		 * Returns true if this object is double.
		 */
		bool IsDouble();
		/**
		 * Returns true if this object is string.
		 */
		bool IsString();
		/**
		 * Returns true if this object is function.
		 */
		bool IsFunction();
		/**
		 * Returns true if this object is object.
		 */
		bool IsObject();

		/**
		 * Returns true if this object is array.
		 */
		bool IsArray();
		/**
		 * Returns true if this object is array.
		 */
		bool IsTypedArray();

		/**
		 * Returns length if this object is array/typedarray. Otherwise 0
		 */
		unsigned int GetLength();

		/**
		 * Convert this object to boolean.
		 */
		bool ToBool();
		/**
		 * Convert this object to integer.
		 */
		int ToInt();
		/**
		 * Convert this object to double.
		 */
		double ToDouble();
		/**
		 * Convert this object to string.
		 */
		CString ToString();

		/**
		 * Get property of this object.
		 */
		CDocBuilderValue GetProperty(const wchar_t* name);

		/**
		 * Similars for GetProperty
		 */
		CDocBuilderValue Get(const char* name);
		CDocBuilderValue Get(const wchar_t* name);
		CDocBuilderValue operator[](const char* name);
		CDocBuilderValue operator[](const wchar_t* name);

		/**
		 * Methods for arrays. Get the value by index.
		 */
		CDocBuilderValue Get(const int& index);
		CDocBuilderValue operator[](const int& index);

		/**
		 * Set property of this object.
		 */
		void SetProperty(const wchar_t* name, CDocBuilderValue value);
		void Set(const wchar_t* name, CDocBuilderValue value);
		void Set(const int& index, CDocBuilderValue value);

	public:
		// primitives
		CDocBuilderValue(const bool& value);
		CDocBuilderValue(const int& value);
		CDocBuilderValue(const unsigned int& value);
		CDocBuilderValue(const double& value);
		CDocBuilderValue(const char* value);
		CDocBuilderValue(const wchar_t* value);

		/**
		 * Please use CDocBuilderContext::CreateUndefined
		 * This method gets the current context and call method of it.
		 */
		static CDocBuilderValue CreateUndefined();
		/**
		 * Please use CDocBuilderContext::CreateNull
		 * This method gets the current context and call method of it.
		 */
		static CDocBuilderValue CreateNull();

	public:
		/**
		 * Methods for functions. Call method of object. Many functions for siplest writing code.
		 */
		CDocBuilderValue Call(const char* name);
		CDocBuilderValue Call(const char* name, CDocBuilderValue p1);
		CDocBuilderValue Call(const char* name, CDocBuilderValue p1, CDocBuilderValue p2);
		CDocBuilderValue Call(const char* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3);
		CDocBuilderValue Call(const char* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3, CDocBuilderValue p4);
		CDocBuilderValue Call(const char* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3, CDocBuilderValue p4, CDocBuilderValue p5);
		CDocBuilderValue Call(const char* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3, CDocBuilderValue p4, CDocBuilderValue p5, CDocBuilderValue p6);

		CDocBuilderValue Call(const wchar_t* name);
		CDocBuilderValue Call(const wchar_t* name, CDocBuilderValue p1);
		CDocBuilderValue Call(const wchar_t* name, CDocBuilderValue p1, CDocBuilderValue p2);
		CDocBuilderValue Call(const wchar_t* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3);
		CDocBuilderValue Call(const wchar_t* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3, CDocBuilderValue p4);
		CDocBuilderValue Call(const wchar_t* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3, CDocBuilderValue p4, CDocBuilderValue p5);
		CDocBuilderValue Call(const wchar_t* name, CDocBuilderValue p1, CDocBuilderValue p2, CDocBuilderValue p3, CDocBuilderValue p4, CDocBuilderValue p5, CDocBuilderValue p6);

	private:
		CDocBuilderValue_Private* m_internal;

		friend class CDocBuilderContext;
	};

	/**
	 * Stack-allocated class which sets the execution context for all
	 * operations executed within a local scope.
	 * All opened scopes will be closed automatically, when builder CloseFile method will be called.
	 */
	class CDocBuilderContextScope_Private;
	class Q_DECL_EXPORT CDocBuilderContextScope
	{
	public:
		CDocBuilderContextScope();
		CDocBuilderContextScope(const CDocBuilderContextScope& src);
		CDocBuilderContextScope& operator=(const CDocBuilderContextScope& src);
		~CDocBuilderContextScope();

		/**
		 * Close this scope. This method will be called automatically on destructor.
		 */
		void Close();

	private:
		CDocBuilderContextScope_Private* m_internal;

		friend class CDocBuilderContext;
	};

	/**
	 * Class for getting js context for working
	 */
	class CDocBuilderContext_Private;
	class Q_DECL_EXPORT CDocBuilderContext
	{
	public:
		CDocBuilderContext();
		CDocBuilderContext(const CDocBuilderContext& src);
		CDocBuilderContext& operator=(const CDocBuilderContext& src);
		~CDocBuilderContext();

		/*
		 * Create undefined value. Analog of undefined in js.
		 */
		CDocBuilderValue CreateUndefined();
		/*
		 * Create null value. Analog of null in js.
		 */
		CDocBuilderValue CreateNull();
		/*
		 * Create empty object. Analog of {} in js.
		 */
		CDocBuilderValue CreateObject();
		/*
		 * Create array value. Analog of new Array(length) in js.
		 */
		CDocBuilderValue CreateArray(const int& length);
		/*
		 * Create Uint8Array value. Analog of Uint8Array in js. If externalize == true, application need release memory after Uint8Array release,
		 * else memory will be freed automatically, but buffer had to created with AllocMemoryTypedArray method.
		 */
		CDocBuilderValue CreateTypedArray(unsigned char* buffer, const int& length, const bool& externalize);

		/*
		 * Method for allocation memory for typed array.
		 */
		static unsigned char* AllocMemoryTypedArray(const size_t& size);
		/*
		 * Method for free memory for typed array.
		 */
		static void FreeMemoryTypedArray(unsigned char* data, const size_t& size);

		/*
		 * Get the global object for context.
		 */
		CDocBuilderValue GetGlobal();

		/*
		 * Create the scope for context.
		 */
		CDocBuilderContextScope CreateScope();

		/*
		 * Check errors in js. Error message and callstack will be written to std::cerr.
		 */
		bool IsError();

	private:
		CDocBuilderContext_Private* m_internal;

		friend class CDocBuilder_Private;
		friend class CDocBuilder;
	};

	class CDocBuilder_Private;
	class Q_DECL_EXPORT CDocBuilder
	{
	public:
		CDocBuilder();
		~CDocBuilder();

	public:
		/**
		 * Open the document file which will be edited and saved afterwards.
		 * @param path Path or url to the document
		 * @param params Additions for x2t convertation in xml format
		 * @return Process x2t return code
		 */
		int OpenFile(const wchar_t* path, const wchar_t* params);
		/**
		 * Create a new file.
		 * @param type Type of document (see AVS_OFFICESTUDIO_FILE_XXX values).
		 * @return Is success
		 */
		bool CreateFile(const int& type);
		/**
		 * The path to the folder where the program will temporarily save files needed for the
		 * program correct work. After the successful document file creation all the files will
		 * be deleted from the folder. If no temporary folder is set, the system one will be used.
		 * @param folder Path to the temp folder
		 */
		void SetTmpFolder(const wchar_t* folder);
		/**
		 * Save the file after all the changes are made.
		 * @param type Type of need format. (see AVS_OFFICESTUDIO_FILE_XXX values).
		 * @param path Destination file path.
		 * @param params Additions for x2t convertation in xml format
		 * @return Process x2t return code
		 */
		int SaveFile(const int& type, const wchar_t* path, const wchar_t* params = 0);
		/**
		 * Close the file to stop working with it. You can use a single ONLYOFFICE Document Builder instance
		 * to work with all your files, but you need to close the previous file before you can
		 * start working with the next one in this case.
		 *
		 * Attention!!!
		 * There is always a chance that you will need to exchange the data among the documents.
		 * For example, you might need to open some document, copy style from it, or some data values,
		 * close the document, create a new one and paste the copied data to it or use it to form some report.
		 * But once you close the file (using the CloseFile method (or new OpenFile), all the variable data you worked
		 * with will be void and cleared, and you will not be able to use it with any other file.
		 * To exchange the data between the files GlobalVariable is introduced.
		 * What you need, is to create a variable in the first opened or created file using the GlobalVariable method, e.g.:
		 * builder.OpenFile("file1");
		 * var tmpVariable = Api.GetDocument().GetCommentsReport();
		 * GlobalVariable["CommentsReport"] = tmpVariable;
		 * builder.CloseFile();
		 * builder.OpenFile("file2");
		 * tmpVariable now undefined
		 * GlobalVariable["CommentsReport"] - valid object
		 */
		void CloseFile();
		/**
		 * Execute the command which will be used to create the document file (text document, spreadsheet, PDF, etc.).
		 * @param command Javascript code
		 * @param retValue Return value of command
		 * @return Is success
		 */
		bool ExecuteCommand(const wchar_t* command, CDocBuilderValue* retValue = 0);

		/**
		 * Run ONLYOFFICE Document Builder executable. If you do not want to write a C++ application,
		 * you can simply use the docbuilder.exe executable file and run it with the .docbuilder file as an argument,
		 * where all the code for the document file creation will be written. For C++ the path to the
		 * executable file from the sPath parameter must be used, the CDocBuilder object created and the Run method is called.
		 * @param path Path to the script
		 * @return Is success
		 */
		bool Run(const wchar_t* path);

		/**
		 * Run the all the commands for the document creation using a single command.
		 * Compared to ExecuteCommand where only one command at a time is allowed, RunText(W)/(A)
		 * makes it possible to enter all the commands for the document creation at once.
		 * @param commands Commands script content
		 * @return Is success
		 */
		bool RunTextW(const wchar_t* commands);
		bool RunTextA(const char* commands);

		/**
		 * Set property to builder class
		 * Supported props:
		 * --use-doctrenderer-scheme true/false Is use building doc or get content from editor on saving file.
		 * Default: false
		 * --check-fonts true/false Is cache system fonts for faster working
		 * Default: true
		 * --work-directory Path to the temp directory
		 * Default: ""
		 * --cache-scripts true/false Is cache sdkjs scripts
		 * Default: true
		 * --save-use-only-names Is not use destination paths (for server work). /home/user/1.txt => /tmp/1.txt
		 * Default: false
		 * --all-fonts-path Path to AllFonts.js script
		 * --argument Json argument, sending to global params of all opened js context
		 * --fonts-system true/false Is use system fonts. Default true
		 * --fonts-dir Path to additional fonts dir. (may be many records)
		 * @param param key
		 * @param value value
		 */
		void SetProperty(const char* param, const wchar_t* value);
		/**
		 * Unicode version of the SetProperty method
		 */
		void SetPropertyW(const wchar_t* param, const wchar_t* value);

		/**
		 * Write data to file. Used for logs in js code.
		 */
		void WriteData(const wchar_t* path, const wchar_t* value, const bool& append);

		/**
		 * IsSaveWithDoctrendererMode
		 * @return Is used doctrenderer mode on saving. See --use-doctrenderer-scheme property.
		 */
		bool IsSaveWithDoctrendererMode();

		/**
		 * GetVersion
		 * @return Get the document builder engine version
		 */
		char* GetVersion();

		/**
		 * GetContext
		 * @return Get the current js context
		 */
		CDocBuilderContext GetContext();

	public:
		/**
		 * Initializing the ONLYOFFICE Document Builder as a library for the application to be able to work with it.
		 * This method just set directory to main builder resources. (icu files and etc). If this methos was not called,
		 * builder will found resources from currect process directory.
		 */
		static void Initialize(const wchar_t* directory = 0);
		/**
		 * Unloading the ONLYOFFICE Document Builder from the application memory when it is no longer needed.
		 * It should generally not be necessary to dispose js before exiting
		 * a process, this should happen automatically.  It is only necessary
		 * to use if the process needs the resources taken up by js.
		 */
		static void Dispose();

		/*
		 * Do not use this method. Is is for internal needs.
		 */
		CDocBuilder_Private* GetPrivate() { return m_pInternal; }

	private:
		CDocBuilder_Private* m_pInternal;

		friend class CBuilderDocumentEmbed;
	};

	/**
	 * Attention!!!
	 * If you use the builder as an application and a script, then you need to know some limitations.
	 *
	 * 1) docbuilder.exe "path-to-script.docbuilder"
	 * This this is the same as
	 * NSDoctRenderer::CDocBuilder::Initialize();
	 * CDocBuilder builder;
	 * builder.Run("path-to-script.docbuilder");
	 * NSDoctRenderer::CDocBuilder::Dispose();
	 *
	 * 2) argument
	 * docbuilder.exe "--argument={\"company\":\"ONLYOFFICE\",\"product\":\"ONLYOFFICE Document Builder\"}" "path-to-script.docbuilder"
	 * This set the --argument property to CDocBuilder & Run (see point 1)
	 * Using in javascript:
	 * var sCompany   = Argument["company"];
	 * var sProduct = Argument["product"];
	 *
	 * 3) Methods of the "builder" object cannot be called with values - js variables. If necessary, then you need to
	 * wrap it in an instruction "jsValue", e.g.:
	 * var jsVar = "123.docx";
	 * builder.SaveFile("docx", jsVar); // ERROR
	 * builder.SaveFile("docx", jsValue(jsVar)); // GOOD
	 *
	 * 4) For convenience, format types have been replaced with strings
	 * builder.CreateFile("docx");
	 * This this is the same as CDocBuilder.CreateFile(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX);
	 * builder.SaveFile("docx", file_path);
	 * This this is the same as CDocBuilder.SaveFile("docx", file_path);
	 *
	 * All names:
	 * "docx": AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX;
	 * "doc": AVS_OFFICESTUDIO_FILE_DOCUMENT_DOC;
	 * "odt": AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT;
	 * "rtf": AVS_OFFICESTUDIO_FILE_DOCUMENT_RTF;
	 * "txt": AVS_OFFICESTUDIO_FILE_DOCUMENT_TXT;
	 * "pptx": AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTX;
	 * "odp": AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP;
	 * "xlsx": AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX;
	 * "xls": AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLS;
	 * "ods": AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS;
	 * "csv": AVS_OFFICESTUDIO_FILE_SPREADSHEET_CSV;
	 * "pdf": AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_PDF;
	 * "image": AVS_OFFICESTUDIO_FILE_IMAGE;
	 * "jpg": AVS_OFFICESTUDIO_FILE_IMAGE;
	 * "png": AVS_OFFICESTUDIO_FILE_IMAGE;
	 *
	 * 5) All javascript context present wrapper over native CDocBuilder object: builderJS.
	 * You need to work with it as with an ordinary javascript object. The jsValue instruction is not needed.
	 *
	 * builderJS methods:
	 * builderJS.OpenFile("path_or_url", "x2t_additons_as_xml");
	 * builderJS.CreateFile(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX); or builderJS.CreateFile("docx");
	 * builderJS.SetTmpFolder("folder");
	 * builderJS.SaveFile(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX, "path", "x2t_additons_as_xml"); or builderJS.SaveFile("docx", "path", "x2t_additons_as_xml");
	 * builderJS.CloseFile();
	 *
	 * Attention: The rule under point 4 does not work for the builderJS object
	 *
	 * 6) The builder always works with one file.
	 * But there are times when you need to be able to open another file, not for adding to the content,
	 * but for some manipulations (comparing, mailmerge). For such cases, the builder provides a method OpenTmpFile
	 *
	 * var tmpFile = builderJS.OpenTmpFile("path_or_url");
	 *
	 * interface of tmpFile:
	 * IsValid() : return boolean value
	 * GetBinary() : return Uint8Array with doct/pptt/xlst binary content
	 * GetFolder() : return string path to the tmp folder with tmp file content
	 * Close() : close file (remove content of the tmp folder)
	 * GetImageMap() : return object-dictionary with key-value imageId -> imagePath (for inserting to document)
	 *
	 */

	// typedefs for shorter code
	typedef CDocBuilderValue CValue;
	typedef CDocBuilderContext CContext;
	typedef CDocBuilderContextScope CContextScope;
}

#endif // DOCBUILDER_H
