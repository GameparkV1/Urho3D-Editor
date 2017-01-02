#pragma once

#include <Urho3D/Core/Context.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/IO/PackageFile.h>
#include <QTimer>
#include <QWidget>

namespace Urho3DEditor
{

class Urho3DProject;

class Urho3DWidget : public QWidget, public Urho3D::Object
{
    Q_OBJECT
    URHO3D_OBJECT(Urho3DWidget, Urho3D::Object);

public:
    /// Construct.
    Urho3DWidget(Urho3D::Context* context);
    /// Initialize widget with optional configuration.
    bool SetCurrentProject(Urho3DProject* project);

private slots:
    /// Handle main timer.
    void OnTimer();

protected:
    virtual QPaintEngine * paintEngine() const override;
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void RunFrame();

private:
    /// Engine.
    Urho3D::SharedPtr<Urho3D::Engine> engine_;
    /// Main timer.
    QTimer timer_;

};

}
