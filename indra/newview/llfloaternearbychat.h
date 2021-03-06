 /** 
 * @file llfloaternearbychat.h
 * @brief Nearby chat history scrolling panel implementation
 *
 * $LicenseInfo:firstyear=2004&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 * Copyright (C) 2012, Zi Ree @ Second Life
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#ifndef LL_LLFLOATERNEARBYCHAT_H
#define LL_LLFLOATERNEARBYCHAT_H

#include "lldockablefloater.h"
#include "llscrollbar.h"
#include "llviewerchat.h"

class LLResizeBar;
class LLChatHistory;
// <FS:Zi> Nearby chat bar class
// class LLLineEditor;
#include "lllineeditor.h"
#include "llsingleton.h"
// </FS:Zi>

class LLFloaterNearbyChat: public LLDockableFloater
{
public:
	LLFloaterNearbyChat(const LLSD& key);
	~LLFloaterNearbyChat();

	BOOL	postBuild			();

	/** @param archive true - to save a message to the chat history log */
	void	addMessage			(const LLChat& message,bool archive = true, const LLSD &args = LLSD());	
	void	onNearbyChatContextMenuItemClicked(const LLSD& userdata);
	bool	onNearbyChatCheckContextMenuItem(const LLSD& userdata);

	void	onChatBarVisibilityChanged();
	void	onChatChannelVisibilityChanged();

	// This doesn't seem to apply anymore? It makes the chat and spin box colors
	// appear wrong when focused and unfocused, so disable this. -Zi
#if 0
	virtual BOOL	handleMouseDown(S32 x, S32 y, MASK mask);
	virtual void	draw();

	// focus overrides
	/*virtual*/ void	onFocusLost();
#endif	
	/*virtual*/ void	onFocusReceived();
	/*virtual*/ void	onOpen	(const LLSD& key);

	/*virtual*/ void	setVisible(BOOL visible);
	void	openFloater(const LLSD& key);

	virtual void setRect		(const LLRect &rect);

	void clearChatHistory();
	virtual void updateChatHistoryStyle();

	static void processChatHistoryStyleUpdate(const LLSD& newvalue);

	void loadHistory();

	static LLFloaterNearbyChat* getInstance();
	
	void removeScreenChat();
	
	static bool isChatMultiTab();
	
	BOOL getVisible();

	static void onHistoryButtonClicked(LLUICtrl* ctrl, void* userdata);

	// overridden to fix the multitab focus bug -Zi
	BOOL focusFirstItem(BOOL prefer_text_fields = FALSE, BOOL focus_flash = TRUE );

	void updateFSUseNearbyChatConsole(const LLSD &data);

private:
	void	getAllowedRect		(LLRect& rect);

	void	onNearbySpeakers	();

private:
	LLHandle<LLView>	mPopupMenuHandle;
	LLChatHistory*		mChatHistory;
	
	std::vector<LLChat> mMessageArchive;
	LLLineEditor* mInputEditor;

	BOOL FSUseNearbyChatConsole;
};

#endif
