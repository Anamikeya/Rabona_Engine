#pragma once

#include "Rabona/Core.h"
#include "Rabona/Layer.h"
#include "Rabona/Events/ApplicationEvent.h"
#include "Rabona/Events/MouseEvent.h"
#include "Rabona/Events/KeyEvent.h"


namespace  Rabona
{

	class RABONA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		

		void Begin();
		void End();

		
	private:
		float m_Time = 0;
	};
}

