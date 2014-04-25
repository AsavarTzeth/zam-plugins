/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2014 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef DGL_APP_HPP_INCLUDED
#define DGL_APP_HPP_INCLUDED

#include "Base.hpp"

START_NAMESPACE_DGL

class Window;

// -----------------------------------------------------------------------

class App
{
public:
    class IdleCallback
    {
    public:
        virtual ~IdleCallback() {}
        virtual void idleCallback() = 0;
    };

    App();
    ~App();

    void idle();
    void exec();
    void quit();
    bool isQuiting() const;

    void addIdleCallback(IdleCallback* const callback);
    void removeIdleCallback(IdleCallback* const callback);

private:
    struct PrivateData;
    PrivateData* const pData;
    friend class Window;

    void _addWindow(Window* const window);
    void _removeWindow(Window* const window);
    void _oneShown();
    void _oneHidden();

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(App)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DGL

#endif // DGL_APP_HPP_INCLUDED
