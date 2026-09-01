#include "pch-cpp.hpp"





struct VirtualActionInvoker0
{
	typedef void (*Action)(void*,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*,T1,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename T1>
struct VirtualActionInvoker1Invoker;
template <typename T1>
struct VirtualActionInvoker1Invoker<T1*>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		void* params[1] = { p1 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[0]);
	}
};
template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3
{
	typedef void (*Action)(void*,T1,T2,T3,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,p2,p3,invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3Invoker;
template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3Invoker<T1*, T2*, T3>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1, T2* p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		void* params[3] = { p1, p2, &p3 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[2]);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker;
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		R ret;
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*,T1,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1Invoker;
template <typename T1>
struct InterfaceActionInvoker1Invoker<T1*>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		void* params[1] = { p1 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[0]);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*,T1,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2)
	{
		void* params[2] = { p1, &p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		R ret;
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588;
struct Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E;
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC;
struct EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581;
struct Func_2_t135085FEAA39127D86C31D5991376887D3C220A9;
struct Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08;
struct Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4;
struct Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA;
struct Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41;
struct Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B;
struct Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619;
struct Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22;
struct Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470;
struct Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB;
struct Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E;
struct Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852;
struct Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A;
struct Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115;
struct Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76;
struct Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F;
struct Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B;
struct Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05;
struct Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D;
struct Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938;
struct Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87;
struct Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B;
struct Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0;
struct Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE;
struct Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899;
struct Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A;
struct Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7;
struct Func_2_t93FE63D487003DC89C264F70099E05071B9C1169;
struct Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595;
struct Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4;
struct Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F;
struct Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9;
struct Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821;
struct IEnumerable_1_tD14E2E6D4448FC02EEB50A306F6C22CAC3281815;
struct IEnumerable_1_t5359DEC999AA35C7E2DE775B0455A4760550ED7F;
struct IEnumerable_1_tE7085BC52C5ABEB257F7DD997C7553035F1B6424;
struct IEnumerable_1_tE8770DCFF3ECE985F417877349BCE1223B1DA79E;
struct IEnumerable_1_tE925592D6CE31E7FA5349FCEE9007F3DF53409FD;
struct IEnumerable_1_tDE18BB328ED95FB272AE8FAE3C13576909589F4D;
struct IEnumerable_1_t6D5FFB1B4A97F30426C5D394135AD0D2FAEAE680;
struct IEnumerable_1_t29E7244AE33B71FA0981E50D5BC73B7938F35C66;
struct IEnumerable_1_t9C73E2DA2A24734B7BEE3997930B156A82172C56;
struct IEnumerable_1_tB1CBD8584610F6122FB9F16A9A9985BB7CCD1711;
struct IEnumerable_1_t7886238EF7DC77A68D0FBB352FED1C732EF306A0;
struct IEnumerator_1_tC027B9C75091151E01521B33507D9483DDF76923;
struct IEnumerator_1_t6999C610E1C05F2C90151CD5C41E24528ACB3255;
struct IEnumerator_1_tBBAE7A086BB8551DBC40DA5D2D737592B6A23443;
struct IEnumerator_1_t74105E6C32CA7AC4F4202BB870BF99B1C95BA2DE;
struct IEnumerator_1_t4CA3732E083480E40018894623B3C184576E5EFD;
struct IEnumerator_1_t28314E682493CA936A454DA48BFB000CAF4F5D74;
struct IEnumerator_1_tB41B292FAFD525FC5C54D7E469F0BA1A193CA8B1;
struct IEnumerator_1_t75CB2681E18F7F2791528FA2CA60361FDB5DA08D;
struct IEnumerator_1_tF74C952F97E24A4AFD21162637D82942513CB35B;
struct IEnumerator_1_tFB94D0AF6D95F58DEC65B8B3CEFC8EA4F2418CB2;
struct IEnumerator_1_tF129A86A709F185A2268C6A66EEC790456389E7C;
struct IObservable_1_t901035633D48F4662F07B1CB3EA42409B32B9104;
struct IObservable_1_tA29A83F0C2D67B7465AEA27D123F8F8B6514E475;
struct IObserver_1_t175B69025D6DF34D18D3E1EDA5BDF648762F03DB;
struct IObserver_1_t094BE2515872266E98A772AEA02B413105F16A8B;
struct Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D;
struct Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32;
struct Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0;
struct Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563;
struct List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B;
struct List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6;
struct List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43;
struct List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06;
struct List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF;
struct List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29;
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255;
struct List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7;
struct List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A;
struct VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3;
struct VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86;
struct WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180;
struct Where_t8628A3898F012DDE1FB9931908812596C248A533;
struct Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C;
struct WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547;
struct WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6;
struct WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A;
struct WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C;
struct WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2;
struct WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B;
struct WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B;
struct WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121;
struct WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0;
struct WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07;
struct WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0;
struct WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816;
struct WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92;
struct WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC;
struct WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE;
struct WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3;
struct WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E;
struct WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A;
struct WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB;
struct WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E;
struct WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98;
struct WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7;
struct WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55;
struct WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE;
struct WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD;
struct WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375;
struct WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174;
struct WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60;
struct WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379;
struct WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9;
struct WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6;
struct WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB;
struct WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98;
struct WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1;
struct WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C;
struct WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15;
struct WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866;
struct WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1;
struct WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE;
struct WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366;
struct WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7;
struct WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52;
struct WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90;
struct WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6;
struct WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C;
struct WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C;
struct WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD;
struct WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601;
struct WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B;
struct WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51;
struct WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1;
struct WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52;
struct WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76;
struct WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D;
struct WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81;
struct WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4;
struct WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C;
struct WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197;
struct WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA;
struct WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1;
struct WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7;
struct WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3;
struct WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A;
struct WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9;
struct WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336;
struct WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F;
struct WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285;
struct WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E;
struct WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C;
struct KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5;
struct NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2;
struct NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B;
struct SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297;
struct ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104;
struct JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3;
struct LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
struct Exception_t;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5;
struct IFormatterConverter_t726606DAC82C384B08C82471313C340968DDB609;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct Light_t1E68479B7782AF2050FAA02A5DC612FD034F18F3;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72;

IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral4EBC86E0EACFCA522AEB82874860D0E248D782A5;
IL2CPP_EXTERN_C String_t* _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0;
IL2CPP_EXTERN_C String_t* _stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7;
IL2CPP_EXTERN_C String_t* _stringLiteralA5E215A6DBE803E908043576B18C4FAD26AD44F7;
IL2CPP_EXTERN_C String_t* _stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085;
IL2CPP_EXTERN_C const RuntimeMethod* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61;
struct InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5;
struct NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2;
struct NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A;
struct StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B;
struct SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77;
struct Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297;
struct ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104;
struct JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3;
struct LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC  : public RuntimeObject
{
};
struct EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581  : public RuntimeObject
{
};
struct Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	Il2CppSharedGenericObject* ___current;
};
struct Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0 : public RuntimeObject {};
struct List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B  : public RuntimeObject
{
	KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6  : public RuntimeObject
{
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43  : public RuntimeObject
{
	NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06  : public RuntimeObject
{
	NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF  : public RuntimeObject
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29  : public RuntimeObject
{
	SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E  : public RuntimeObject
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255  : public RuntimeObject
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7  : public RuntimeObject
{
	ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A  : public RuntimeObject
{
	JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Where_t8628A3898F012DDE1FB9931908812596C248A533  : public RuntimeObject
{
	WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* ___m_Observable;
	RuntimeObject* ___m_Observer;
};
struct Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C  : public RuntimeObject
{
	WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816* ___m_Observable;
	RuntimeObject* ___m_Observer;
};
struct WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0  : public RuntimeObject
{
	RuntimeObject* ___m_Source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___m_Predicate;
};
struct WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816  : public RuntimeObject
{
	RuntimeObject* ___m_Source;
	Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___m_Predicate;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37  : public RuntimeObject
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_members;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___m_data;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___m_types;
	Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588* ___m_nameToIndex;
	int32_t ___m_currMember;
	RuntimeObject* ___m_converter;
	String_t* ___m_fullTypeName;
	String_t* ___m_assemName;
	Type_t* ___objectType;
	bool ___isFullTypeNameSetExplicit;
	bool ___isAssemblyNameSetExplicit;
	bool ___requireSameTokenInPartialTrust;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72  : public RuntimeObject
{
	bool ___m_OverrideState;
};
struct Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ____list;
	int32_t ____index;
	int32_t ____version;
	Il2CppSharedGenericObject* ____current;
};
typedef Il2CppFullySharedGenericStruct Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF;
struct Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 
{
	List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ____list;
	int32_t ____index;
	int32_t ____version;
	int32_t ____current;
};
struct ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 
{
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___m_Array;
	int32_t ___m_StartIndex;
	int32_t ___m_Length;
};
struct ReadOnlyArray_1_t1B44D48F2E9F425D218BABD5DE616117E8725D41 
{
	NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___m_Array;
	int32_t ___m_StartIndex;
	int32_t ___m_Length;
};
struct ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 
{
	NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___m_Array;
	int32_t ___m_StartIndex;
	int32_t ___m_Length;
};
struct VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3 : public VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72 {};
struct VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86  : public VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72
{
	int32_t ___m_Value;
};
struct WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	int32_t ___index;
};
struct WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6 : public RuntimeObject {};
struct WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B : public RuntimeObject {};
struct WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___source;
	Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___predicate;
	Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___source;
	Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___predicate;
	Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___source;
	Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___predicate;
	Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___source;
	Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___predicate;
	Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174 : public RuntimeObject {};
struct WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___source;
	Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___predicate;
	Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___source;
	Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___predicate;
	Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___selector;
	int32_t ___index;
};
struct WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___predicate;
	Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___predicate;
	Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___predicate;
	Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___predicate;
	Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C : public RuntimeObject {};
struct WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___predicate;
	Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___predicate;
	Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___selector;
	RuntimeObject* ___enumerator;
};
struct WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44 
{
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___m_Data;
	int32_t ___m_Start;
	int32_t ___m_Length;
};
struct WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809 
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___m_Data;
	int32_t ___m_Start;
	int32_t ___m_Length;
};
struct WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87 
{
	LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___m_Data;
	int32_t ___m_Start;
	int32_t ___m_Length;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED 
{
	int32_t ___m_Code;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 
{
	String_t* ___m_StringOriginalCase;
	String_t* ___m_StringLowerCase;
};
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke
{
	char* ___m_StringOriginalCase;
	char* ___m_StringLowerCase;
};
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com
{
	Il2CppChar* ___m_StringOriginalCase;
	Il2CppChar* ___m_StringLowerCase;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849 
{
	String_t* ___m_String;
	int32_t ___m_Index;
	int32_t ___m_Length;
};
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke
{
	char* ___m_String;
	int32_t ___m_Index;
	int32_t ___m_Length;
};
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com
{
	Il2CppChar* ___m_String;
	int32_t ___m_Index;
	int32_t ___m_Length;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 
{
	uint16_t ___visibleLightIndex;
	uint16_t ___lightBufferIndex;
	Light_t1E68479B7782AF2050FAA02A5DC612FD034F18F3* ___light;
};
struct LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_marshaled_pinvoke
{
	uint16_t ___visibleLightIndex;
	uint16_t ___lightBufferIndex;
	Light_t1E68479B7782AF2050FAA02A5DC612FD034F18F3* ___light;
};
struct LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_marshaled_com
{
	uint16_t ___visibleLightIndex;
	uint16_t ___lightBufferIndex;
	Light_t1E68479B7782AF2050FAA02A5DC612FD034F18F3* ___light;
};
struct Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D 
{
	List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ____list;
	int32_t ____index;
	int32_t ____version;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ____current;
};
struct Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 
{
	List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ____list;
	int32_t ____index;
	int32_t ____version;
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ____current;
};
struct Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___current;
};
struct WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 ___enumerator;
};
struct WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0 : public RuntimeObject {};
struct WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___selector;
	Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 ___enumerator;
};
struct WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336 : public RuntimeObject {};
struct WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___source;
	Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___predicate;
	Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___selector;
	Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 ___enumerator;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle;
};
struct GCHandleType_t4CD45A3495E593D093AB0CE36EF9EC1A1572F82A 
{
	int32_t ___value__;
};
struct NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 
{
	String_t* ___U3CnameU3Ek__BackingField;
	ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 ___U3CparametersU3Ek__BackingField;
};
struct NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01_marshaled_pinvoke
{
	char* ___U3CnameU3Ek__BackingField;
	ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 ___U3CparametersU3Ek__BackingField;
};
struct NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01_marshaled_com
{
	Il2CppChar* ___U3CnameU3Ek__BackingField;
	ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 ___U3CparametersU3Ek__BackingField;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct StreamingContextStates_t5EE358E619B251608A9327618C7BFE8638FC33C1 
{
	int32_t ___value__;
};
struct StyleSelectorType_t425962DE6D175F785FA2B5554D793B71D39430A3 
{
	int32_t ___value__;
};
struct TypeCode_tBEF9BE86C8BCF5A6B82F3381219738D27804EF79 
{
	int32_t ___value__;
};
struct JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB 
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___text;
	bool ___hasEscapes;
};
struct JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_pinvoke
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke ___text;
	int32_t ___hasEscapes;
};
struct JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_com
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com ___text;
	int32_t ___hasEscapes;
};
struct JsonValueType_t36BA339F107E5E9C0966C45F896E27F3BCC5A2AB 
{
	int32_t ___value__;
};
struct Flags_t36D5070200D1061BA68BF41808748FA000DEE57C 
{
	int32_t ___value__;
};
struct Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 
{
	List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ____list;
	int32_t ____index;
	int32_t ____version;
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ____current;
};
struct WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180  : public RuntimeObject
{
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ___handle;
	bool ___trackResurrection;
};
struct WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___source;
	Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___predicate;
	Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___source;
	Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___predicate;
	Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___source;
	Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___predicate;
	Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___source;
	Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___predicate;
	Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___source;
	Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___predicate;
	Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___source;
	Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___predicate;
	Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___selector;
	int32_t ___index;
};
struct WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___predicate;
	Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___predicate;
	Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___predicate;
	Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___predicate;
	Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___predicate;
	Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	RuntimeObject* ___source;
	Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___predicate;
	Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___selector;
	Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D ___enumerator;
};
struct WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___source;
	Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___predicate;
	Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___selector;
	Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D ___enumerator;
};
struct WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___source;
	Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___predicate;
	Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___selector;
	Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 ___enumerator;
};
struct WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___source;
	Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___predicate;
	Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___selector;
	Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 ___enumerator;
};
struct WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___selector;
	Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 ___enumerator;
};
struct WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___source;
	Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___predicate;
	Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___selector;
	Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 ___enumerator;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___m_Type;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___m_Type_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_BoolValue_OffsetPadding[4];
			bool ___m_BoolValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_BoolValue_OffsetPadding_forAlignmentOnly[4];
			bool ___m_BoolValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_CharValue_OffsetPadding[4];
			Il2CppChar ___m_CharValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_CharValue_OffsetPadding_forAlignmentOnly[4];
			Il2CppChar ___m_CharValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ByteValue_OffsetPadding[4];
			uint8_t ___m_ByteValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ByteValue_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_ByteValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_SByteValue_OffsetPadding[4];
			int8_t ___m_SByteValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_SByteValue_OffsetPadding_forAlignmentOnly[4];
			int8_t ___m_SByteValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ShortValue_OffsetPadding[4];
			int16_t ___m_ShortValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ShortValue_OffsetPadding_forAlignmentOnly[4];
			int16_t ___m_ShortValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UShortValue_OffsetPadding[4];
			uint16_t ___m_UShortValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UShortValue_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___m_UShortValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_IntValue_OffsetPadding[4];
			int32_t ___m_IntValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_IntValue_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_IntValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UIntValue_OffsetPadding[4];
			uint32_t ___m_UIntValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UIntValue_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___m_UIntValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_LongValue_OffsetPadding[4];
			int64_t ___m_LongValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_LongValue_OffsetPadding_forAlignmentOnly[4];
			int64_t ___m_LongValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ULongValue_OffsetPadding[4];
			uint64_t ___m_ULongValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ULongValue_OffsetPadding_forAlignmentOnly[4];
			uint64_t ___m_ULongValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_FloatValue_OffsetPadding[4];
			float ___m_FloatValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_FloatValue_OffsetPadding_forAlignmentOnly[4];
			float ___m_FloatValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_DoubleValue_OffsetPadding[4];
			double ___m_DoubleValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_DoubleValue_OffsetPadding_forAlignmentOnly[4];
			double ___m_DoubleValue_forAlignmentOnly;
		};
	};
};
struct PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_pinvoke
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___m_Type;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___m_Type_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_BoolValue_OffsetPadding[4];
			int32_t ___m_BoolValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_BoolValue_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_BoolValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_CharValue_OffsetPadding[4];
			uint8_t ___m_CharValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_CharValue_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_CharValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ByteValue_OffsetPadding[4];
			uint8_t ___m_ByteValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ByteValue_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_ByteValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_SByteValue_OffsetPadding[4];
			int8_t ___m_SByteValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_SByteValue_OffsetPadding_forAlignmentOnly[4];
			int8_t ___m_SByteValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ShortValue_OffsetPadding[4];
			int16_t ___m_ShortValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ShortValue_OffsetPadding_forAlignmentOnly[4];
			int16_t ___m_ShortValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UShortValue_OffsetPadding[4];
			uint16_t ___m_UShortValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UShortValue_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___m_UShortValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_IntValue_OffsetPadding[4];
			int32_t ___m_IntValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_IntValue_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_IntValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UIntValue_OffsetPadding[4];
			uint32_t ___m_UIntValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UIntValue_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___m_UIntValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_LongValue_OffsetPadding[4];
			int64_t ___m_LongValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_LongValue_OffsetPadding_forAlignmentOnly[4];
			int64_t ___m_LongValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ULongValue_OffsetPadding[4];
			uint64_t ___m_ULongValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ULongValue_OffsetPadding_forAlignmentOnly[4];
			uint64_t ___m_ULongValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_FloatValue_OffsetPadding[4];
			float ___m_FloatValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_FloatValue_OffsetPadding_forAlignmentOnly[4];
			float ___m_FloatValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_DoubleValue_OffsetPadding[4];
			double ___m_DoubleValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_DoubleValue_OffsetPadding_forAlignmentOnly[4];
			double ___m_DoubleValue_forAlignmentOnly;
		};
	};
};
struct PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_com
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___m_Type;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___m_Type_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_BoolValue_OffsetPadding[4];
			int32_t ___m_BoolValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_BoolValue_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_BoolValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_CharValue_OffsetPadding[4];
			uint8_t ___m_CharValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_CharValue_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_CharValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ByteValue_OffsetPadding[4];
			uint8_t ___m_ByteValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ByteValue_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_ByteValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_SByteValue_OffsetPadding[4];
			int8_t ___m_SByteValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_SByteValue_OffsetPadding_forAlignmentOnly[4];
			int8_t ___m_SByteValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ShortValue_OffsetPadding[4];
			int16_t ___m_ShortValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ShortValue_OffsetPadding_forAlignmentOnly[4];
			int16_t ___m_ShortValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UShortValue_OffsetPadding[4];
			uint16_t ___m_UShortValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UShortValue_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___m_UShortValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_IntValue_OffsetPadding[4];
			int32_t ___m_IntValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_IntValue_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_IntValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UIntValue_OffsetPadding[4];
			uint32_t ___m_UIntValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UIntValue_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___m_UIntValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_LongValue_OffsetPadding[4];
			int64_t ___m_LongValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_LongValue_OffsetPadding_forAlignmentOnly[4];
			int64_t ___m_LongValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ULongValue_OffsetPadding[4];
			uint64_t ___m_ULongValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ULongValue_OffsetPadding_forAlignmentOnly[4];
			uint64_t ___m_ULongValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_FloatValue_OffsetPadding[4];
			float ___m_FloatValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_FloatValue_OffsetPadding_forAlignmentOnly[4];
			float ___m_FloatValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_DoubleValue_OffsetPadding[4];
			double ___m_DoubleValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_DoubleValue_OffsetPadding_forAlignmentOnly[4];
			double ___m_DoubleValue_forAlignmentOnly;
		};
	};
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 
{
	RuntimeObject* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_pinvoke
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_com
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 
{
	String_t* ___m_Value;
	int32_t ___m_Type;
	RuntimeObject* ___tempData;
};
struct StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470_marshaled_pinvoke
{
	char* ___m_Value;
	int32_t ___m_Type;
	Il2CppIUnknown* ___tempData;
};
struct StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470_marshaled_com
{
	Il2CppChar* ___m_Value;
	int32_t ___m_Type;
	Il2CppIUnknown* ___tempData;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct JsonValue_t01DB320267C848E729A400EF2345979978F851D2 
{
	int32_t ___type;
	bool ___boolValue;
	double ___realValue;
	int64_t ___integerValue;
	JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB ___stringValue;
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___arrayValue;
	Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E* ___objectValue;
	RuntimeObject* ___anyValue;
};
struct JsonValue_t01DB320267C848E729A400EF2345979978F851D2_marshaled_pinvoke
{
	int32_t ___type;
	int32_t ___boolValue;
	double ___realValue;
	int64_t ___integerValue;
	JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_pinvoke ___stringValue;
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___arrayValue;
	Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E* ___objectValue;
	Il2CppIUnknown* ___anyValue;
};
struct JsonValue_t01DB320267C848E729A400EF2345979978F851D2_marshaled_com
{
	int32_t ___type;
	int32_t ___boolValue;
	double ___realValue;
	int64_t ___integerValue;
	JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_com ___stringValue;
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___arrayValue;
	Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E* ___objectValue;
	Il2CppIUnknown* ___anyValue;
};
struct Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F 
{
	List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ____list;
	int32_t ____index;
	int32_t ____version;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ____current;
};
struct Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB 
{
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ____list;
	int32_t ____index;
	int32_t ____version;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ____current;
};
struct Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA  : public MulticastDelegate_t
{
};
struct Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41  : public MulticastDelegate_t
{
};
struct Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B  : public MulticastDelegate_t
{
};
struct Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619  : public MulticastDelegate_t
{
};
struct Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22  : public MulticastDelegate_t
{
};
struct Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470  : public MulticastDelegate_t
{
};
struct Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A  : public MulticastDelegate_t
{
};
struct Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115  : public MulticastDelegate_t
{
};
struct Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76  : public MulticastDelegate_t
{
};
struct Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F  : public MulticastDelegate_t
{
};
struct Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B  : public MulticastDelegate_t
{
};
struct Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05  : public MulticastDelegate_t
{
};
struct Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D  : public MulticastDelegate_t
{
};
struct Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938  : public MulticastDelegate_t
{
};
struct Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87  : public MulticastDelegate_t
{
};
struct Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B  : public MulticastDelegate_t
{
};
struct Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0  : public MulticastDelegate_t
{
};
struct Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE  : public MulticastDelegate_t
{
};
struct Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899  : public MulticastDelegate_t
{
};
struct Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A  : public MulticastDelegate_t
{
};
struct Func_2_t93FE63D487003DC89C264F70099E05071B9C1169  : public MulticastDelegate_t
{
};
struct Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595  : public MulticastDelegate_t
{
};
struct Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4  : public MulticastDelegate_t
{
};
struct Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F  : public MulticastDelegate_t
{
};
struct Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9  : public MulticastDelegate_t
{
};
struct Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821  : public MulticastDelegate_t
{
};
struct KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 
{
	Il2CppSharedGenericObject* ___key;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___value;
};
struct WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___source;
	Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___predicate;
	Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___selector;
	Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 ___enumerator;
};
struct WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___source;
	Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___predicate;
	Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___selector;
	Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 ___enumerator;
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED 
{
	String_t* ___U3CnameU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___U3CvalueU3Ek__BackingField;
};
struct NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED_marshaled_pinvoke
{
	char* ___U3CnameU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_pinvoke ___U3CvalueU3Ek__BackingField;
};
struct NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED_marshaled_com
{
	Il2CppChar* ___U3CnameU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_com ___U3CvalueU3Ek__BackingField;
};
struct ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD 
{
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___U3CnameU3Ek__BackingField;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___U3ClayoutU3Ek__BackingField;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___U3CvariantsU3Ek__BackingField;
	String_t* ___U3CuseStateFromU3Ek__BackingField;
	String_t* ___U3CdisplayNameU3Ek__BackingField;
	String_t* ___U3CshortDisplayNameU3Ek__BackingField;
	ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 ___U3CusagesU3Ek__BackingField;
	ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 ___U3CaliasesU3Ek__BackingField;
	ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 ___U3CparametersU3Ek__BackingField;
	ReadOnlyArray_1_t1B44D48F2E9F425D218BABD5DE616117E8725D41 ___U3CprocessorsU3Ek__BackingField;
	uint32_t ___U3CoffsetU3Ek__BackingField;
	uint32_t ___U3CbitU3Ek__BackingField;
	uint32_t ___U3CsizeInBitsU3Ek__BackingField;
	FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED ___U3CformatU3Ek__BackingField;
	int32_t ___U3CflagsU3Ek__BackingField;
	int32_t ___U3CarraySizeU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___U3CdefaultStateU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___U3CminValueU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___U3CmaxValueU3Ek__BackingField;
};
struct ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_marshaled_pinvoke
{
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke ___U3CnameU3Ek__BackingField;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke ___U3ClayoutU3Ek__BackingField;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke ___U3CvariantsU3Ek__BackingField;
	char* ___U3CuseStateFromU3Ek__BackingField;
	char* ___U3CdisplayNameU3Ek__BackingField;
	char* ___U3CshortDisplayNameU3Ek__BackingField;
	ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 ___U3CusagesU3Ek__BackingField;
	ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 ___U3CaliasesU3Ek__BackingField;
	ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 ___U3CparametersU3Ek__BackingField;
	ReadOnlyArray_1_t1B44D48F2E9F425D218BABD5DE616117E8725D41 ___U3CprocessorsU3Ek__BackingField;
	uint32_t ___U3CoffsetU3Ek__BackingField;
	uint32_t ___U3CbitU3Ek__BackingField;
	uint32_t ___U3CsizeInBitsU3Ek__BackingField;
	FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED ___U3CformatU3Ek__BackingField;
	int32_t ___U3CflagsU3Ek__BackingField;
	int32_t ___U3CarraySizeU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_pinvoke ___U3CdefaultStateU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_pinvoke ___U3CminValueU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_pinvoke ___U3CmaxValueU3Ek__BackingField;
};
struct ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_marshaled_com
{
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com ___U3CnameU3Ek__BackingField;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com ___U3ClayoutU3Ek__BackingField;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com ___U3CvariantsU3Ek__BackingField;
	Il2CppChar* ___U3CuseStateFromU3Ek__BackingField;
	Il2CppChar* ___U3CdisplayNameU3Ek__BackingField;
	Il2CppChar* ___U3CshortDisplayNameU3Ek__BackingField;
	ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 ___U3CusagesU3Ek__BackingField;
	ReadOnlyArray_1_t1C2864D7CF4D444AB2616316AC8DD33932F77064 ___U3CaliasesU3Ek__BackingField;
	ReadOnlyArray_1_t4A15F7D15ACB297B45A08889D51E4CACEAD4EDF9 ___U3CparametersU3Ek__BackingField;
	ReadOnlyArray_1_t1B44D48F2E9F425D218BABD5DE616117E8725D41 ___U3CprocessorsU3Ek__BackingField;
	uint32_t ___U3CoffsetU3Ek__BackingField;
	uint32_t ___U3CbitU3Ek__BackingField;
	uint32_t ___U3CsizeInBitsU3Ek__BackingField;
	FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED ___U3CformatU3Ek__BackingField;
	int32_t ___U3CflagsU3Ek__BackingField;
	int32_t ___U3CarraySizeU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_com ___U3CdefaultStateU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_com ___U3CminValueU3Ek__BackingField;
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_com ___U3CmaxValueU3Ek__BackingField;
};
struct Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 
{
	List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ____list;
	int32_t ____index;
	int32_t ____version;
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ____current;
};
struct Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 
{
	List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ____list;
	int32_t ____index;
	int32_t ____version;
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ____current;
};
struct Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0 
{
	List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* ____list;
	int32_t ____index;
	int32_t ____version;
	ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD ____current;
};
struct Func_2_t135085FEAA39127D86C31D5991376887D3C220A9  : public MulticastDelegate_t
{
};
struct Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08  : public MulticastDelegate_t
{
};
struct Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4  : public MulticastDelegate_t
{
};
struct Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB  : public MulticastDelegate_t
{
};
struct Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E  : public MulticastDelegate_t
{
};
struct Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852  : public MulticastDelegate_t
{
};
struct Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7  : public MulticastDelegate_t
{
};
struct Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD ___current;
};
struct WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___selector;
	Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F ___enumerator;
};
struct WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___selector;
	Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F ___enumerator;
};
struct WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___source;
	Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___predicate;
	Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___selector;
	Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB ___enumerator;
};
struct WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___source;
	Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___predicate;
	Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___selector;
	Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB ___enumerator;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A  : public Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563
{
	ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* ___source;
	Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___predicate;
	int32_t ___index;
};
struct WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B  : public Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563
{
	RuntimeObject* ___source;
	Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07  : public Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563
{
	List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* ___source;
	Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___predicate;
	Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0 ___enumerator;
};
struct WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___source;
	Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___predicate;
	Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___selector;
	Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 ___enumerator;
};
struct WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___source;
	Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___predicate;
	Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___selector;
	Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 ___enumerator;
};
struct WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C  : public Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D
{
	List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___source;
	Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___predicate;
	Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___selector;
	Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 ___enumerator;
};
struct WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___source;
	Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___predicate;
	Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___selector;
	Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 ___enumerator;
};
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC_StaticFields
{
	EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* ___defaultComparer;
};
struct EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581_StaticFields
{
	EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* ___defaultComparer;
};
struct List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B_StaticFields
{
	KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___s_emptyArray;
};
struct List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6_StaticFields
{
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___s_emptyArray;
};
struct List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43_StaticFields
{
	NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___s_emptyArray;
};
struct List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06_StaticFields
{
	NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___s_emptyArray;
};
struct List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF_StaticFields
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___s_emptyArray;
};
struct List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29_StaticFields
{
	SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___s_emptyArray;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
};
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___s_emptyArray;
};
struct List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7_StaticFields
{
	ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* ___s_emptyArray;
};
struct List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A_StaticFields
{
	JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___s_emptyArray;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_StaticFields
{
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___zeroVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___oneVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___positiveInfinityVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___negativeInfinityVector;
};
struct LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_StaticFields
{
	Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___s_CompareByCookieSize;
	Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___s_CompareByBufferIndex;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppSharedGenericObject* m_Items[1];

	inline Il2CppSharedGenericObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Il2CppSharedGenericObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104  : public RuntimeArray
{
	ALIGN_FIELD (8) ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD m_Items[1];

	inline ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CnameU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CnameU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3ClayoutU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3ClayoutU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CvariantsU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CvariantsU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CuseStateFromU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CdisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CshortDisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CusagesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CaliasesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CprocessorsU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
	}
	inline ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CnameU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CnameU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3ClayoutU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3ClayoutU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CvariantsU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CvariantsU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CuseStateFromU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CdisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CshortDisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CusagesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CaliasesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CprocessorsU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
	}
};
struct KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 m_Items[1];

	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&((m_Items + index)->___value))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___anyValue), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&((m_Items + index)->___value))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___anyValue), (void*)NULL);
		#endif
	}
};
struct InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5  : public RuntimeArray
{
	ALIGN_FIELD (8) InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 m_Items[1];

	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringLowerCase), (void*)NULL);
		#endif
	}
	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringLowerCase), (void*)NULL);
		#endif
	}
};
struct NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2  : public RuntimeArray
{
	ALIGN_FIELD (8) NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 m_Items[1];

	inline NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CnameU3Ek__BackingField), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
	}
	inline NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CnameU3Ek__BackingField), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
	}
};
struct NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A  : public RuntimeArray
{
	ALIGN_FIELD (8) NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED m_Items[1];

	inline NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CnameU3Ek__BackingField), (void*)NULL);
	}
	inline NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CnameU3Ek__BackingField), (void*)NULL);
	}
};
struct StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B  : public RuntimeArray
{
	ALIGN_FIELD (8) StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 m_Items[1];

	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Value), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___tempData), (void*)NULL);
		#endif
	}
	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Value), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___tempData), (void*)NULL);
		#endif
	}
};
struct SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77  : public RuntimeArray
{
	ALIGN_FIELD (8) Substring_t2E16755269E6716C22074D6BC0A9099915E67849 m_Items[1];

	inline Substring_t2E16755269E6716C22074D6BC0A9099915E67849 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Substring_t2E16755269E6716C22074D6BC0A9099915E67849* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_String), (void*)NULL);
	}
	inline Substring_t2E16755269E6716C22074D6BC0A9099915E67849 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Substring_t2E16755269E6716C22074D6BC0A9099915E67849* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_String), (void*)NULL);
	}
};
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3  : public RuntimeArray
{
	ALIGN_FIELD (8) JsonValue_t01DB320267C848E729A400EF2345979978F851D2 m_Items[1];

	inline JsonValue_t01DB320267C848E729A400EF2345979978F851D2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline JsonValue_t01DB320267C848E729A400EF2345979978F851D2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___stringValue))->___text))->___m_String), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___anyValue), (void*)NULL);
		#endif
	}
	inline JsonValue_t01DB320267C848E729A400EF2345979978F851D2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline JsonValue_t01DB320267C848E729A400EF2345979978F851D2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___stringValue))->___text))->___m_String), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___anyValue), (void*)NULL);
		#endif
	}
};
struct Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD  : public RuntimeArray
{
	ALIGN_FIELD (8) Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 m_Items[1];

	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 value)
	{
		m_Items[index] = value;
	}
};
struct LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263  : public RuntimeArray
{
	ALIGN_FIELD (8) LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 m_Items[1];

	inline LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___light), (void*)NULL);
	}
	inline LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___light), (void*)NULL);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1__ctor_m70508BCB9F5865418A150EE673A6427870A59465_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, int32_t ___0_value, bool ___1_overrideState, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* EqualityComparer_1_get_Default_mC0B29FC6AFED03D8A30BE41AC4BEC15DCF6AA9F8_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_op_Equality_m5FD3D0F9F083CA946C24FEE5315560B181F1D4C0_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_lhs, int32_t ___1_rhs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_Equals_m8ED6C08D00A26D41DD9529DE530240A83EAF381E_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VolumeParameter_GetValue_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE40AE16776FF3B42C9A2683D870A5648BACFC0D6_gshared (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, bool ___1_trackResurrection, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_gshared_inline (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD_gshared (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5_gshared (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate1, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_mC38D09ED8D96D1D64B7C357F04D5569F8231837F_gshared (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m0C3CAA1BDBAA7573FC25AD65F502E6C666B089E7_gshared (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* __this, ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_gshared_inline (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* __this, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* Enumerable_CombinePredicates_TisControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_mD2B49AA9212177D38B017D33CCE9233E3E5AA947_gshared (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___0_predicate1, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943_gshared (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4_gshared (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B_gshared (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_gshared_inline (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* Enumerable_CombinePredicates_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_mF2B98D83EF1AA959DC98FAC180FA2C16DB6E21BB_gshared (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate1, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100_gshared (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m52C3E4AB52EE018DFBE97FF259F9CCBF2F2498E0_gshared (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, RuntimeObject* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m9B46AEDB129561EFB4315D054CB6C4FF811B03D8_gshared (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_gshared_inline (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25_gshared (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m5FAFE85609CE304AA9F43211F0AB34D1C6C77F6B_gshared (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* __this, List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0 List_1_GetEnumerator_m37A8F02E3D82B04207F54C6A4D70EFBF2B7E080B_gshared (List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD Enumerator_get_Current_m932259DC5443095A2D7AE244692FBCCD52A92261_gshared_inline (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m8784F0F24421DA9476E0E4240A25D7760B24EF46_gshared (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where__ctor_mB320D4A16B60EB5C93B756BC6EF4F58C18738A0D_gshared (Where_t8628A3898F012DDE1FB9931908812596C248A533* __this, WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* ___0_observable, RuntimeObject* ___1_observer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mCFD30A36FBFA5C4FDFF9E98B1F93C0817BF96CEB_gshared (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_gshared_inline (Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_gshared_inline (Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mF15F5CBE5D879FD46EC11C8A9FA1625B851CED70_gshared (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_gshared_inline (Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m5BDDAA0BA9083F3F3CBF215938C50A366082D6A8_gshared (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_gshared_inline (Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m20E6415BC3B791E2A14DEC1291C7D32F0E59C503_gshared (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_gshared_inline (Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m854F57E851CE957E1887DF7D9681E348D5B93BD2_gshared (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* __this, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_gshared_inline (Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_gshared_inline (Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m7C9B21069925BAB022EAA5389E494114D7E65E87_gshared (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* __this, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_gshared_inline (Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m9372C76DEE0D08D5E2CC6F8E118283B2D9BDE32B_gshared (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* __this, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_gshared_inline (Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_gshared_inline (Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mDA0E627B9B299EE9CE197C69DC68EE158E14096F_gshared (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* __this, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_gshared_inline (Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m75517CAAB359671310703010E1BBE16A3367974C_gshared (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_gshared_inline (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_gshared_inline (Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m7FA46E216E6C6F344CA4F2EFDAED7C1ECB2608C3_gshared (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_gshared_inline (Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m16BFD018A35DE6CAC3F62621710A5BD2FC1C8A4C_gshared (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* __this, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_gshared_inline (Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_gshared_inline (Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m67C715A12D5EA7E5ED4904A18B3A6486C0E25AE5_gshared (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* __this, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_gshared_inline (Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mB36566E259A4A615754DE7005361780B06CC6240_gshared (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_gshared_inline (Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_gshared_inline (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mA98660451992CB2678A013CAF4CFE71538EB94DD_gshared (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_gshared_inline (Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* __this, int32_t ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_gshared_inline (Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* __this, int32_t ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m0D34CE1A5CC641C5B010E503A0EDABA731F37317_gshared (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_gshared_inline (Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* __this, int32_t ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m5E9395DC536466521AEEEAF170431DF4B9176166_gshared (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* __this, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_gshared_inline (Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_gshared_inline (Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m88597229D15D44A261E426CB2681EABEAEF6F7EA_gshared (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* __this, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_gshared_inline (Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m06D1F87A96E06281D76DB47276AB2EDAA06B3CA0_gshared (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, RuntimeObject* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m3E31112974492F14302B2F2AD44556E3F190D600_gshared (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, RuntimeObject* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m7C83BFD2FAE565BCEAA43B821FC018C4809E4329_gshared (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m864CB7770F7267D05BAD1722C5B1A733D0D2F11D_gshared (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m23B52E787C9DD0F0644C7C1193C70E0FC4D5F716_gshared (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, RuntimeObject* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mA5886BEC6AD8C08CAA9D486ED97CECF94967ACE3_gshared (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, RuntimeObject* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m970919BF72719E9D8530FAEAAB5BE98DE0C88E86_gshared (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, RuntimeObject* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m11F43BDE67D2B239BB9318EF2B46930EB217CFB1_gshared (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, RuntimeObject* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m6A8FE8B4D2F17ADBC21012752F7F3BC952BAB662_gshared (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m2405C69F4B379D95DB5A0CD878DE173EF4EFC01B_gshared (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m25883F753A672BA40B723092E5FC096E5FD3E024_gshared (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, RuntimeObject* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mEC4706B25165670D334B167CE048A3853D57B94D_gshared (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, RuntimeObject* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mB87A71FACBF4EB861E6D35FCEEB809C46B5E3F1D_gshared (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m70325D0D69B22E471DBC07A8E4CA5D45E5853186_gshared (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, RuntimeObject* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mA846116E73B9D1D46FEF744F0F0DEA950C8BA2C4_gshared (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, RuntimeObject* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m10782D149F90A9C4AB58038312DE7F0D44331AC3_gshared (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, RuntimeObject* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m68319D9F7493E465D7A4220D85AC66B5F966B918_gshared (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, RuntimeObject* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mFBB5A1617EF8B21105D01DEDB300F632817367CF_gshared (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* __this, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 List_1_GetEnumerator_m1F0AB872867D4F4E39ADA790F9BAEEE7C4C041A4_gshared (List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 Enumerator_get_Current_mFED85C73E83B80F77C323CED265F927D8F56A4C2_gshared_inline (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m5C678E13B1EA842DC0035C25A5B4C317B298B675_gshared (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m875604B216BC3B2A7CB3F2C7D5E835D7EB22427F_gshared (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* __this, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mF85D17BE66C1306EFCDD26409BE55B790F79EAC7_gshared (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* __this, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D List_1_GetEnumerator_m29A75776B211A8A73BA0F0BDD4EE3F8AFB4F57D5_gshared (List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Enumerator_get_Current_m6E5830352E5082086B6B8F79AB4DABC2A18414A3_gshared_inline (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mFF6CD854E66A32544CE8D1C58A74C324CE2E822E_gshared (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m5D37B1A65702955D7E80CA7E5D969190926DBF55_gshared (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* __this, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mD72ECEB2A0980E5F93455365BA960143A34085DB_gshared (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* __this, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 List_1_GetEnumerator_mE145D413FF6CDAE7061E3B5CED7823B0EFCBB7F5_gshared (List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 Enumerator_get_Current_mE64095D45062ABD3FE097C12C8A767F4378A3658_gshared_inline (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m43A6E06C5BF5734DB6AD0687EF52131A51F0FCC8_gshared (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m10ACDEF2EB1838C9CC59D697642D3A2C761E5772_gshared (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* __this, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mACC4D7CA5223D22CBC36F756CA54BA80C06723C9_gshared (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* __this, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 List_1_GetEnumerator_m8E8CDE0EBC3A66F0257FD41A31A4055983A0665B_gshared (List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED Enumerator_get_Current_m83264A170B9E2284E4A91DD95D9E58A4AC7A065D_gshared_inline (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m8FDA47B1AB6128A33F2C41EAA3448D67A00A51C5_gshared (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mA2BC01EC05747FCB2048C22517C86446C3F307AB_gshared (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* __this, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m9435C8BAA035BE07F3983A2F3C06D5F3F2EF97BF_gshared (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751_gshared (List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_gshared_inline (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E_gshared (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m4E5213AEA3F49172211F4EFA18DF14269D3DCEFE_gshared (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m76DFD3D8B5B62444383A84BE159C61CBE99D98DA_gshared (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* __this, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 List_1_GetEnumerator_m2E8AAA332A1CCE110C46806675D27756C848C264_gshared (List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Substring_t2E16755269E6716C22074D6BC0A9099915E67849 Enumerator_get_Current_m543479141C23CB5A761FFAE440388CA38F12F73A_gshared_inline (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mBD8837024473F97D1F793AD3DF5E27568D7BDD06_gshared (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6A90F8B7CC3A2042DF6441296DB1FFC2D5862FF6_gshared (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* __this, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mF00B95B59197D6CEA2311875016BA798A7180FD4_gshared (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mAC9D7E0CCA4B15AEFA7AF154091F7E82E23A1C25_gshared (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 List_1_GetEnumerator_mEF61540761E14807B2930879741EF5E1E973FCE8_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Enumerator_get_Current_m27A9B9D3732FA85AE5063328B42817D18F991988_gshared_inline (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m6054C979BCD753583C00269861523701392B935A_gshared (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mDD1F6B9427F21DDC9B7304C6445F4CE23F01B2F5_gshared (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mA16961886A67BC49FFE65D6057D3BA28D407DF89_gshared (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* __this, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB List_1_GetEnumerator_mE2A3E04FB3B522B90EBAC4EFFF9614F47FE19D13_gshared (List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR JsonValue_t01DB320267C848E729A400EF2345979978F851D2 Enumerator_get_Current_m9F9305DFA7957A66E104431A3EB3D5C071B4587D_gshared_inline (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m698365CC16BD65E80A0737FD26ED23F19C8AE5DF_gshared (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m366B0E85B127808BA5964E491DFF0091C853529C_gshared (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* __this, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_m8B26C5F2B3AB3C05CB4ACDE5A17C6559BDEF503C_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 WorkSlice_1_get_Item_m31D876CE45C89B17D24E2D2EB6534C4150D72EE5_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_set_Item_m242025FA56F79603361582298B70AB2284A12067_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_gshared_inline (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_capacity_m514E3E1482974088A807521F9E2C481EB83C25F8_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sorting_QuickSort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mB8556CFA6B9237741AAA1ADF2EE68AA3696F9477_gshared (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_data, int32_t ___1_start, int32_t ___2_end, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* ___3_compare, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_Sort_m9DF994BABD5BF00DE8FEB14D82F7A0A9F6CAEE3D_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* ___0_compare, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_mFEB81358558CEF0264CCE077535DB880EA2492BA_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_m7AC3CC7AABC83B76D23D2B94329DD4D0200156FA_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_get_Item_mFDEC427E08156ECD6879AD45AEE3618B43E3F726_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_set_Item_m757F8BE76FAE27C149DE7C474A2B1845E08A5A0F_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_gshared_inline (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_capacity_mCF0D603B7EC6E6037D0E1A14D8D0F49AD063E59E_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_Sort_mE2ED392BDF8F4F4141D7BF4C984EFE943F607A94_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9* ___0_compare, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_m76CCC65E3DFB8B84A2154B65A79B56688F9B26A4_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 WorkSlice_1_get_Item_mFD8EE50B88077F3EF9BCEF97BD6D0352D2E8445D_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_set_Item_m070889CA2F62E82384BAB3CEF6D6E9AABF153663_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, int32_t ___0_index, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_gshared_inline (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_capacity_m98A237D126494A11FF3C61211B36A790E4E8A3B0_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sorting_QuickSort_TisLightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_mD7019ED48D20810C1169430283118F96945E9450_gshared (LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_data, int32_t ___1_start, int32_t ___2_end, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___3_compare, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_Sort_m7EF532E936D55845DAAC606C0A214FE48EBF8584_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___0_compare, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* EqualityComparer_1_CreateComparer_mFA29AAFB8E37E401F19B2D5CC3E3C877B467E449_gshared (const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter__ctor_m1A76B3C6C284C912F55F7C7E6EF21A18AF3930D2 (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Boolean_GetHashCode_mEDB6904770C962BAF4510E5D24F08083C33900E3 (bool* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
inline void VolumeParameter_1__ctor_m70508BCB9F5865418A150EE673A6427870A59465 (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, int32_t ___0_value, bool ___1_overrideState, const RuntimeMethod* method)
{
	((  void (*) (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*, int32_t, bool, const RuntimeMethod*))VolumeParameter_1__ctor_m70508BCB9F5865418A150EE673A6427870A59465_gshared)(__this, ___0_value, ___1_overrideState, method);
}
inline EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* EqualityComparer_1_get_Default_mC0B29FC6AFED03D8A30BE41AC4BEC15DCF6AA9F8_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_mC0B29FC6AFED03D8A30BE41AC4BEC15DCF6AA9F8_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enum_Equals_m96B1058BA6312E23F31A5FBF594E96EB692EAF4E (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
inline bool VolumeParameter_1_op_Equality_m5FD3D0F9F083CA946C24FEE5315560B181F1D4C0 (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_lhs, int32_t ___1_rhs, const RuntimeMethod* method)
{
	return ((  bool (*) (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*, int32_t, const RuntimeMethod*))VolumeParameter_1_op_Equality_m5FD3D0F9F083CA946C24FEE5315560B181F1D4C0_gshared)(___0_lhs, ___1_rhs, method);
}
inline bool VolumeParameter_1_Equals_m8ED6C08D00A26D41DD9529DE530240A83EAF381E (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_other, const RuntimeMethod* method)
{
	return ((  bool (*) (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*, VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*, const RuntimeMethod*))VolumeParameter_1_Equals_m8ED6C08D00A26D41DD9529DE530240A83EAF381E_gshared)(__this, ___0_other, method);
}
inline int32_t VolumeParameter_GetValue_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE40AE16776FF3B42C9A2683D870A5648BACFC0D6 (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*, const RuntimeMethod*))VolumeParameter_GetValue_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE40AE16776FF3B42C9A2683D870A5648BACFC0D6_gshared)(__this, method);
}
inline void WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, bool ___1_trackResurrection, const RuntimeMethod* method)
{
	((  void (*) (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180*, Il2CppSharedGenericObject*, bool, const RuntimeMethod*))WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E_gshared)(__this, ___0_target, ___1_trackResurrection, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC (RuntimeObject* ___0_value, int32_t ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool SerializationInfo_GetBoolean_m8335F8E11B572AB6B5BF85A9355D6888D5847EF5 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_mC52253CB19C98F82A26E32C941F8F20E106D4C0D (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, bool ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_m28FE9B110F21DDB8FF5F5E35A0EABD659DB22C2F (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GCHandle_set_Target_m1DB05E14910747D2A74ACEB4C48028C4AEBFCF3D_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GCHandle_Free_m1320A260E487EB1EA6D95F9E54BFFCB5A4EF83A3 (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogException_mAB3F4DC7297ED8FBB49DAA718B70E59A6B0171B0 (Exception_t* ___0_exception, const RuntimeMethod* method) ;
inline bool Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Il2CppSharedGenericObject*, const RuntimeMethod*))Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_gshared_inline)(__this, ___0_arg, method);
}
inline void Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*, const RuntimeMethod*))Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5 (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate1, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* (*) (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void Iterator_1__ctor_mC38D09ED8D96D1D64B7C357F04D5569F8231837F (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*, const RuntimeMethod*))Iterator_1__ctor_mC38D09ED8D96D1D64B7C357F04D5569F8231837F_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_m0C3CAA1BDBAA7573FC25AD65F502E6C666B089E7 (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* __this, ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A*, ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104*, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7*, const RuntimeMethod*))WhereArrayIterator_1__ctor_m0C3CAA1BDBAA7573FC25AD65F502E6C666B089E7_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline bool Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_inline (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* __this, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7*, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD, const RuntimeMethod*))Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* Enumerable_CombinePredicates_TisControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_mD2B49AA9212177D38B017D33CCE9233E3E5AA947 (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___0_predicate1, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* (*) (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7*, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7*, const RuntimeMethod*))Enumerable_CombinePredicates_TisControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_mD2B49AA9212177D38B017D33CCE9233E3E5AA947_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943 (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*, const RuntimeMethod*))Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943_gshared)(__this, method);
}
inline void WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4 (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*, RuntimeObject*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*, const RuntimeMethod*))Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B_gshared)(__this, method);
}
inline bool Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*))Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* Enumerable_CombinePredicates_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_mF2B98D83EF1AA959DC98FAC180FA2C16DB6E21BB (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate1, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* (*) (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, const RuntimeMethod*))Enumerable_CombinePredicates_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_mF2B98D83EF1AA959DC98FAC180FA2C16DB6E21BB_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377 (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*, RuntimeObject*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100 (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*, const RuntimeMethod*))Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100_gshared)(__this, method);
}
inline void WhereEnumerableIterator_1__ctor_m52C3E4AB52EE018DFBE97FF259F9CCBF2F2498E0 (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, RuntimeObject* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B*, RuntimeObject*, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m52C3E4AB52EE018DFBE97FF259F9CCBF2F2498E0_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m9B46AEDB129561EFB4315D054CB6C4FF811B03D8 (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*, const RuntimeMethod*))Iterator_1_Dispose_m9B46AEDB129561EFB4315D054CB6C4FF811B03D8_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, const RuntimeMethod*))List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9_gshared)(__this, method);
}
inline Il2CppSharedGenericObject* Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*, const RuntimeMethod*))Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25 (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*, const RuntimeMethod*))Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_m5FAFE85609CE304AA9F43211F0AB34D1C6C77F6B (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* __this, List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07*, List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7*, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7*, const RuntimeMethod*))WhereListIterator_1__ctor_m5FAFE85609CE304AA9F43211F0AB34D1C6C77F6B_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0 List_1_GetEnumerator_m37A8F02E3D82B04207F54C6A4D70EFBF2B7E080B (List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0 (*) (List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7*, const RuntimeMethod*))List_1_GetEnumerator_m37A8F02E3D82B04207F54C6A4D70EFBF2B7E080B_gshared)(__this, method);
}
inline ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD Enumerator_get_Current_m932259DC5443095A2D7AE244692FBCCD52A92261_inline (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* __this, const RuntimeMethod* method)
{
	return ((  ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD (*) (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0*, const RuntimeMethod*))Enumerator_get_Current_m932259DC5443095A2D7AE244692FBCCD52A92261_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m8784F0F24421DA9476E0E4240A25D7760B24EF46 (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0*, const RuntimeMethod*))Enumerator_MoveNext_m8784F0F24421DA9476E0E4240A25D7760B24EF46_gshared)(__this, method);
}
inline void Where__ctor_mB320D4A16B60EB5C93B756BC6EF4F58C18738A0D (Where_t8628A3898F012DDE1FB9931908812596C248A533* __this, WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* ___0_observable, RuntimeObject* ___1_observer, const RuntimeMethod* method)
{
	((  void (*) (Where_t8628A3898F012DDE1FB9931908812596C248A533*, WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0*, RuntimeObject*, const RuntimeMethod*))Where__ctor_mB320D4A16B60EB5C93B756BC6EF4F58C18738A0D_gshared)(__this, ___0_observable, ___1_observer, method);
}
inline void WhereSelectArrayIterator_2__ctor_mCFD30A36FBFA5C4FDFF9E98B1F93C0817BF96CEB (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92*, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61*, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mCFD30A36FBFA5C4FDFF9E98B1F93C0817BF96CEB_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline (Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*))Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_inline (Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*))Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mF15F5CBE5D879FD46EC11C8A9FA1625B851CED70 (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC*, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61*, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mF15F5CBE5D879FD46EC11C8A9FA1625B851CED70_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_inline (Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*))Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m5BDDAA0BA9083F3F3CBF215938C50A366082D6A8 (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE*, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m5BDDAA0BA9083F3F3CBF215938C50A366082D6A8_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_inline (Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*))Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m20E6415BC3B791E2A14DEC1291C7D32F0E59C503 (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3*, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m20E6415BC3B791E2A14DEC1291C7D32F0E59C503_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_inline (Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*))Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m854F57E851CE957E1887DF7D9681E348D5B93BD2 (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* __this, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E*, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2*, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m854F57E851CE957E1887DF7D9681E348D5B93BD2_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline (Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01, const RuntimeMethod*))Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_inline (Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22*, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01, const RuntimeMethod*))Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m7C9B21069925BAB022EAA5389E494114D7E65E87 (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* __this, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A*, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2*, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m7C9B21069925BAB022EAA5389E494114D7E65E87_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_inline (Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470*, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01, const RuntimeMethod*))Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m9372C76DEE0D08D5E2CC6F8E118283B2D9BDE32B (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* __this, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB*, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A*, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m9372C76DEE0D08D5E2CC6F8E118283B2D9BDE32B_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline (Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED, const RuntimeMethod*))Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_inline (Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E*, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED, const RuntimeMethod*))Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mDA0E627B9B299EE9CE197C69DC68EE158E14096F (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* __this, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E*, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A*, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mDA0E627B9B299EE9CE197C69DC68EE158E14096F_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_inline (Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852*, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED, const RuntimeMethod*))Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m75517CAAB359671310703010E1BBE16A3367974C (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98*, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m75517CAAB359671310703010E1BBE16A3367974C_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*))Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_inline (Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*))Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m7FA46E216E6C6F344CA4F2EFDAED7C1ECB2608C3 (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7*, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m7FA46E216E6C6F344CA4F2EFDAED7C1ECB2608C3_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_inline (Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*))Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m16BFD018A35DE6CAC3F62621710A5BD2FC1C8A4C (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* __this, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55*, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77*, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m16BFD018A35DE6CAC3F62621710A5BD2FC1C8A4C_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline (Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Substring_t2E16755269E6716C22074D6BC0A9099915E67849, const RuntimeMethod*))Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_inline (Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B*, Substring_t2E16755269E6716C22074D6BC0A9099915E67849, const RuntimeMethod*))Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m67C715A12D5EA7E5ED4904A18B3A6486C0E25AE5 (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* __this, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE*, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77*, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m67C715A12D5EA7E5ED4904A18B3A6486C0E25AE5_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_inline (Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05*, Substring_t2E16755269E6716C22074D6BC0A9099915E67849, const RuntimeMethod*))Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mB36566E259A4A615754DE7005361780B06CC6240 (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mB36566E259A4A615754DE7005361780B06CC6240_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_inline (Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938*, Il2CppSharedGenericObject*, const RuntimeMethod*))Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120 (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, Il2CppSharedGenericObject*, const RuntimeMethod*))Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mA98660451992CB2678A013CAF4CFE71538EB94DD (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60*, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mA98660451992CB2678A013CAF4CFE71538EB94DD_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline (Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* __this, int32_t ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, int32_t, const RuntimeMethod*))Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_inline (Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* __this, int32_t ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899*, int32_t, const RuntimeMethod*))Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m0D34CE1A5CC641C5B010E503A0EDABA731F37317 (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379*, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m0D34CE1A5CC641C5B010E503A0EDABA731F37317_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_inline (Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* __this, int32_t ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A*, int32_t, const RuntimeMethod*))Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m5E9395DC536466521AEEEAF170431DF4B9176166 (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* __this, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9*, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3*, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m5E9395DC536466521AEEEAF170431DF4B9176166_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline (Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, JsonValue_t01DB320267C848E729A400EF2345979978F851D2, const RuntimeMethod*))Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_gshared_inline)(__this, ___0_arg, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_inline (Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595*, JsonValue_t01DB320267C848E729A400EF2345979978F851D2, const RuntimeMethod*))Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m88597229D15D44A261E426CB2681EABEAEF6F7EA (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* __this, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6*, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3*, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m88597229D15D44A261E426CB2681EABEAEF6F7EA_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_inline (Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4*, JsonValue_t01DB320267C848E729A400EF2345979978F851D2, const RuntimeMethod*))Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m06D1F87A96E06281D76DB47276AB2EDAA06B3CA0 (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, RuntimeObject* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB*, RuntimeObject*, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m06D1F87A96E06281D76DB47276AB2EDAA06B3CA0_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m3E31112974492F14302B2F2AD44556E3F190D600 (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, RuntimeObject* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98*, RuntimeObject*, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m3E31112974492F14302B2F2AD44556E3F190D600_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m7C83BFD2FAE565BCEAA43B821FC018C4809E4329 (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1*, RuntimeObject*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m7C83BFD2FAE565BCEAA43B821FC018C4809E4329_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m864CB7770F7267D05BAD1722C5B1A733D0D2F11D (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C*, RuntimeObject*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m864CB7770F7267D05BAD1722C5B1A733D0D2F11D_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m23B52E787C9DD0F0644C7C1193C70E0FC4D5F716 (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, RuntimeObject* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15*, RuntimeObject*, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m23B52E787C9DD0F0644C7C1193C70E0FC4D5F716_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_mA5886BEC6AD8C08CAA9D486ED97CECF94967ACE3 (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, RuntimeObject* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866*, RuntimeObject*, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_mA5886BEC6AD8C08CAA9D486ED97CECF94967ACE3_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m970919BF72719E9D8530FAEAAB5BE98DE0C88E86 (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, RuntimeObject* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1*, RuntimeObject*, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m970919BF72719E9D8530FAEAAB5BE98DE0C88E86_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m11F43BDE67D2B239BB9318EF2B46930EB217CFB1 (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, RuntimeObject* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE*, RuntimeObject*, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m11F43BDE67D2B239BB9318EF2B46930EB217CFB1_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m6A8FE8B4D2F17ADBC21012752F7F3BC952BAB662 (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366*, RuntimeObject*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m6A8FE8B4D2F17ADBC21012752F7F3BC952BAB662_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m2405C69F4B379D95DB5A0CD878DE173EF4EFC01B (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7*, RuntimeObject*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m2405C69F4B379D95DB5A0CD878DE173EF4EFC01B_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m25883F753A672BA40B723092E5FC096E5FD3E024 (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, RuntimeObject* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52*, RuntimeObject*, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m25883F753A672BA40B723092E5FC096E5FD3E024_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_mEC4706B25165670D334B167CE048A3853D57B94D (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, RuntimeObject* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90*, RuntimeObject*, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_mEC4706B25165670D334B167CE048A3853D57B94D_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_mB87A71FACBF4EB861E6D35FCEEB809C46B5E3F1D (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6*, RuntimeObject*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_mB87A71FACBF4EB861E6D35FCEEB809C46B5E3F1D_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384 (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C*, RuntimeObject*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m70325D0D69B22E471DBC07A8E4CA5D45E5853186 (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, RuntimeObject* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD*, RuntimeObject*, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m70325D0D69B22E471DBC07A8E4CA5D45E5853186_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_mA846116E73B9D1D46FEF744F0F0DEA950C8BA2C4 (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, RuntimeObject* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601*, RuntimeObject*, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_mA846116E73B9D1D46FEF744F0F0DEA950C8BA2C4_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m10782D149F90A9C4AB58038312DE7F0D44331AC3 (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, RuntimeObject* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B*, RuntimeObject*, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m10782D149F90A9C4AB58038312DE7F0D44331AC3_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m68319D9F7493E465D7A4220D85AC66B5F966B918 (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, RuntimeObject* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51*, RuntimeObject*, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m68319D9F7493E465D7A4220D85AC66B5F966B918_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mFBB5A1617EF8B21105D01DEDB300F632817367CF (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* __this, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1*, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B*, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mFBB5A1617EF8B21105D01DEDB300F632817367CF_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 List_1_GetEnumerator_m1F0AB872867D4F4E39ADA790F9BAEEE7C4C041A4 (List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 (*) (List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B*, const RuntimeMethod*))List_1_GetEnumerator_m1F0AB872867D4F4E39ADA790F9BAEEE7C4C041A4_gshared)(__this, method);
}
inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 Enumerator_get_Current_mFED85C73E83B80F77C323CED265F927D8F56A4C2_inline (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 (*) (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01*, const RuntimeMethod*))Enumerator_get_Current_mFED85C73E83B80F77C323CED265F927D8F56A4C2_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m5C678E13B1EA842DC0035C25A5B4C317B298B675 (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01*, const RuntimeMethod*))Enumerator_MoveNext_m5C678E13B1EA842DC0035C25A5B4C317B298B675_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m875604B216BC3B2A7CB3F2C7D5E835D7EB22427F (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* __this, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52*, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B*, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9*, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m875604B216BC3B2A7CB3F2C7D5E835D7EB22427F_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mF85D17BE66C1306EFCDD26409BE55B790F79EAC7 (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* __this, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76*, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mF85D17BE66C1306EFCDD26409BE55B790F79EAC7_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D List_1_GetEnumerator_m29A75776B211A8A73BA0F0BDD4EE3F8AFB4F57D5 (List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D (*) (List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6*, const RuntimeMethod*))List_1_GetEnumerator_m29A75776B211A8A73BA0F0BDD4EE3F8AFB4F57D5_gshared)(__this, method);
}
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Enumerator_get_Current_m6E5830352E5082086B6B8F79AB4DABC2A18414A3_inline (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* __this, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D*, const RuntimeMethod*))Enumerator_get_Current_m6E5830352E5082086B6B8F79AB4DABC2A18414A3_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_mFF6CD854E66A32544CE8D1C58A74C324CE2E822E (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D*, const RuntimeMethod*))Enumerator_MoveNext_mFF6CD854E66A32544CE8D1C58A74C324CE2E822E_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m5D37B1A65702955D7E80CA7E5D969190926DBF55 (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* __this, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D*, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6*, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA*, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m5D37B1A65702955D7E80CA7E5D969190926DBF55_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mD72ECEB2A0980E5F93455365BA960143A34085DB (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* __this, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81*, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43*, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mD72ECEB2A0980E5F93455365BA960143A34085DB_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 List_1_GetEnumerator_mE145D413FF6CDAE7061E3B5CED7823B0EFCBB7F5 (List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 (*) (List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43*, const RuntimeMethod*))List_1_GetEnumerator_mE145D413FF6CDAE7061E3B5CED7823B0EFCBB7F5_gshared)(__this, method);
}
inline NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 Enumerator_get_Current_mE64095D45062ABD3FE097C12C8A767F4378A3658_inline (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* __this, const RuntimeMethod* method)
{
	return ((  NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 (*) (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054*, const RuntimeMethod*))Enumerator_get_Current_mE64095D45062ABD3FE097C12C8A767F4378A3658_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m43A6E06C5BF5734DB6AD0687EF52131A51F0FCC8 (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054*, const RuntimeMethod*))Enumerator_MoveNext_m43A6E06C5BF5734DB6AD0687EF52131A51F0FCC8_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m10ACDEF2EB1838C9CC59D697642D3A2C761E5772 (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* __this, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4*, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43*, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619*, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m10ACDEF2EB1838C9CC59D697642D3A2C761E5772_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mACC4D7CA5223D22CBC36F756CA54BA80C06723C9 (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* __this, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C*, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06*, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mACC4D7CA5223D22CBC36F756CA54BA80C06723C9_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 List_1_GetEnumerator_m8E8CDE0EBC3A66F0257FD41A31A4055983A0665B (List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 (*) (List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06*, const RuntimeMethod*))List_1_GetEnumerator_m8E8CDE0EBC3A66F0257FD41A31A4055983A0665B_gshared)(__this, method);
}
inline NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED Enumerator_get_Current_m83264A170B9E2284E4A91DD95D9E58A4AC7A065D_inline (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* __this, const RuntimeMethod* method)
{
	return ((  NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED (*) (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06*, const RuntimeMethod*))Enumerator_get_Current_m83264A170B9E2284E4A91DD95D9E58A4AC7A065D_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m8FDA47B1AB6128A33F2C41EAA3448D67A00A51C5 (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06*, const RuntimeMethod*))Enumerator_MoveNext_m8FDA47B1AB6128A33F2C41EAA3448D67A00A51C5_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_mA2BC01EC05747FCB2048C22517C86446C3F307AB (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* __this, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197*, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06*, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB*, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mA2BC01EC05747FCB2048C22517C86446C3F307AB_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m9435C8BAA035BE07F3983A2F3C06D5F3F2EF97BF (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA*, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m9435C8BAA035BE07F3983A2F3C06D5F3F2EF97BF_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751 (List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F (*) (List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF*, const RuntimeMethod*))List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751_gshared)(__this, method);
}
inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_inline (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method)
{
	return ((  StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 (*) (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*, const RuntimeMethod*))Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*, const RuntimeMethod*))Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m4E5213AEA3F49172211F4EFA18DF14269D3DCEFE (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1*, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m4E5213AEA3F49172211F4EFA18DF14269D3DCEFE_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m76DFD3D8B5B62444383A84BE159C61CBE99D98DA (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* __this, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7*, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29*, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m76DFD3D8B5B62444383A84BE159C61CBE99D98DA_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 List_1_GetEnumerator_m2E8AAA332A1CCE110C46806675D27756C848C264 (List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 (*) (List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29*, const RuntimeMethod*))List_1_GetEnumerator_m2E8AAA332A1CCE110C46806675D27756C848C264_gshared)(__this, method);
}
inline Substring_t2E16755269E6716C22074D6BC0A9099915E67849 Enumerator_get_Current_m543479141C23CB5A761FFAE440388CA38F12F73A_inline (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* __this, const RuntimeMethod* method)
{
	return ((  Substring_t2E16755269E6716C22074D6BC0A9099915E67849 (*) (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785*, const RuntimeMethod*))Enumerator_get_Current_m543479141C23CB5A761FFAE440388CA38F12F73A_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_mBD8837024473F97D1F793AD3DF5E27568D7BDD06 (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785*, const RuntimeMethod*))Enumerator_MoveNext_mBD8837024473F97D1F793AD3DF5E27568D7BDD06_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m6A90F8B7CC3A2042DF6441296DB1FFC2D5862FF6 (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* __this, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3*, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29*, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F*, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m6A90F8B7CC3A2042DF6441296DB1FFC2D5862FF6_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mF00B95B59197D6CEA2311875016BA798A7180FD4 (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mF00B95B59197D6CEA2311875016BA798A7180FD4_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868 (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mAC9D7E0CCA4B15AEFA7AF154091F7E82E23A1C25 (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F*, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mAC9D7E0CCA4B15AEFA7AF154091F7E82E23A1C25_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 List_1_GetEnumerator_mEF61540761E14807B2930879741EF5E1E973FCE8 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, const RuntimeMethod*))List_1_GetEnumerator_mEF61540761E14807B2930879741EF5E1E973FCE8_gshared)(__this, method);
}
inline int32_t Enumerator_get_Current_m27A9B9D3732FA85AE5063328B42817D18F991988_inline (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*, const RuntimeMethod*))Enumerator_get_Current_m27A9B9D3732FA85AE5063328B42817D18F991988_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m6054C979BCD753583C00269861523701392B935A (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*, const RuntimeMethod*))Enumerator_MoveNext_m6054C979BCD753583C00269861523701392B935A_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_mDD1F6B9427F21DDC9B7304C6445F4CE23F01B2F5 (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285*, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE*, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mDD1F6B9427F21DDC9B7304C6445F4CE23F01B2F5_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mA16961886A67BC49FFE65D6057D3BA28D407DF89 (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* __this, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E*, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A*, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mA16961886A67BC49FFE65D6057D3BA28D407DF89_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB List_1_GetEnumerator_mE2A3E04FB3B522B90EBAC4EFFF9614F47FE19D13 (List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB (*) (List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A*, const RuntimeMethod*))List_1_GetEnumerator_mE2A3E04FB3B522B90EBAC4EFFF9614F47FE19D13_gshared)(__this, method);
}
inline JsonValue_t01DB320267C848E729A400EF2345979978F851D2 Enumerator_get_Current_m9F9305DFA7957A66E104431A3EB3D5C071B4587D_inline (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* __this, const RuntimeMethod* method)
{
	return ((  JsonValue_t01DB320267C848E729A400EF2345979978F851D2 (*) (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB*, const RuntimeMethod*))Enumerator_get_Current_m9F9305DFA7957A66E104431A3EB3D5C071B4587D_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m698365CC16BD65E80A0737FD26ED23F19C8AE5DF (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB*, const RuntimeMethod*))Enumerator_MoveNext_m698365CC16BD65E80A0737FD26ED23F19C8AE5DF_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m366B0E85B127808BA5964E491DFF0091C853529C (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* __this, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C*, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A*, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169*, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m366B0E85B127808BA5964E491DFF0091C853529C_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*, int32_t, int32_t, const RuntimeMethod*))WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF_gshared)(__this, ___0_src, ___1_srcStart, ___2_srcLen, method);
}
inline void WorkSlice_1__ctor_m8B26C5F2B3AB3C05CB4ACDE5A17C6559BDEF503C (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*, int32_t, const RuntimeMethod*))WorkSlice_1__ctor_m8B26C5F2B3AB3C05CB4ACDE5A17C6559BDEF503C_gshared)(__this, ___0_src, ___1_srcLen, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Math_Min_m53C488772A34D53917BCA2A491E79A0A5356ED52 (int32_t ___0_val1, int32_t ___1_val2, const RuntimeMethod* method) ;
inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 WorkSlice_1_get_Item_m31D876CE45C89B17D24E2D2EB6534C4150D72EE5 (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, int32_t, const RuntimeMethod*))WorkSlice_1_get_Item_m31D876CE45C89B17D24E2D2EB6534C4150D72EE5_gshared)(__this, ___0_index, method);
}
inline void WorkSlice_1_set_Item_m242025FA56F79603361582298B70AB2284A12067 (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, int32_t, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3, const RuntimeMethod*))WorkSlice_1_set_Item_m242025FA56F79603361582298B70AB2284A12067_gshared)(__this, ___0_index, ___1_value, method);
}
inline int32_t WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_inline (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, const RuntimeMethod*))WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_gshared_inline)(__this, method);
}
inline int32_t WorkSlice_1_get_capacity_m514E3E1482974088A807521F9E2C481EB83C25F8 (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, const RuntimeMethod*))WorkSlice_1_get_capacity_m514E3E1482974088A807521F9E2C481EB83C25F8_gshared)(__this, method);
}
inline void Sorting_QuickSort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mB8556CFA6B9237741AAA1ADF2EE68AA3696F9477 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_data, int32_t ___1_start, int32_t ___2_end, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* ___3_compare, const RuntimeMethod* method)
{
	((  void (*) (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*, int32_t, int32_t, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F*, const RuntimeMethod*))Sorting_QuickSort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mB8556CFA6B9237741AAA1ADF2EE68AA3696F9477_gshared)(___0_data, ___1_start, ___2_end, ___3_compare, method);
}
inline void WorkSlice_1_Sort_m9DF994BABD5BF00DE8FEB14D82F7A0A9F6CAEE3D (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* ___0_compare, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44*, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F*, const RuntimeMethod*))WorkSlice_1_Sort_m9DF994BABD5BF00DE8FEB14D82F7A0A9F6CAEE3D_gshared)(__this, ___0_compare, method);
}
inline void WorkSlice_1__ctor_mFEB81358558CEF0264CCE077535DB880EA2492BA (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, const RuntimeMethod*))WorkSlice_1__ctor_mFEB81358558CEF0264CCE077535DB880EA2492BA_gshared)(__this, ___0_src, ___1_srcLen, method);
}
inline void WorkSlice_1__ctor_m7AC3CC7AABC83B76D23D2B94329DD4D0200156FA (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, const RuntimeMethod*))WorkSlice_1__ctor_m7AC3CC7AABC83B76D23D2B94329DD4D0200156FA_gshared)(__this, ___0_src, ___1_srcStart, ___2_srcLen, method);
}
inline void WorkSlice_1_get_Item_mFDEC427E08156ECD6879AD45AEE3618B43E3F726 (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, int32_t, Il2CppFullySharedGenericAny*, const RuntimeMethod*))WorkSlice_1_get_Item_mFDEC427E08156ECD6879AD45AEE3618B43E3F726_gshared)((WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*)__this, ___0_index, il2cppRetVal, method);
}
inline void WorkSlice_1_set_Item_m757F8BE76FAE27C149DE7C474A2B1845E08A5A0F (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, int32_t, Il2CppFullySharedGenericAny, const RuntimeMethod*))WorkSlice_1_set_Item_m757F8BE76FAE27C149DE7C474A2B1845E08A5A0F_gshared)((WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*)__this, ___0_index, ___1_value, method);
}
inline int32_t WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_inline (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, const RuntimeMethod*))WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_gshared_inline)(__this, method);
}
inline int32_t WorkSlice_1_get_capacity_mCF0D603B7EC6E6037D0E1A14D8D0F49AD063E59E (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, const RuntimeMethod*))WorkSlice_1_get_capacity_mCF0D603B7EC6E6037D0E1A14D8D0F49AD063E59E_gshared)(__this, method);
}
inline void WorkSlice_1_Sort_mE2ED392BDF8F4F4141D7BF4C984EFE943F607A94 (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9* ___0_compare, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9*, const RuntimeMethod*))WorkSlice_1_Sort_mE2ED392BDF8F4F4141D7BF4C984EFE943F607A94_gshared)(__this, ___0_compare, method);
}
inline void WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0 (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263*, int32_t, int32_t, const RuntimeMethod*))WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0_gshared)(__this, ___0_src, ___1_srcStart, ___2_srcLen, method);
}
inline void WorkSlice_1__ctor_m76CCC65E3DFB8B84A2154B65A79B56688F9B26A4 (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263*, int32_t, const RuntimeMethod*))WorkSlice_1__ctor_m76CCC65E3DFB8B84A2154B65A79B56688F9B26A4_gshared)(__this, ___0_src, ___1_srcLen, method);
}
inline LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 WorkSlice_1_get_Item_mFD8EE50B88077F3EF9BCEF97BD6D0352D2E8445D (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, int32_t, const RuntimeMethod*))WorkSlice_1_get_Item_mFD8EE50B88077F3EF9BCEF97BD6D0352D2E8445D_gshared)(__this, ___0_index, method);
}
inline void WorkSlice_1_set_Item_m070889CA2F62E82384BAB3CEF6D6E9AABF153663 (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, int32_t ___0_index, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 ___1_value, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, int32_t, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2, const RuntimeMethod*))WorkSlice_1_set_Item_m070889CA2F62E82384BAB3CEF6D6E9AABF153663_gshared)(__this, ___0_index, ___1_value, method);
}
inline int32_t WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_inline (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, const RuntimeMethod*))WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_gshared_inline)(__this, method);
}
inline int32_t WorkSlice_1_get_capacity_m98A237D126494A11FF3C61211B36A790E4E8A3B0 (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, const RuntimeMethod*))WorkSlice_1_get_capacity_m98A237D126494A11FF3C61211B36A790E4E8A3B0_gshared)(__this, method);
}
inline void Sorting_QuickSort_TisLightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_mD7019ED48D20810C1169430283118F96945E9450 (LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_data, int32_t ___1_start, int32_t ___2_end, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___3_compare, const RuntimeMethod* method)
{
	((  void (*) (LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263*, int32_t, int32_t, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821*, const RuntimeMethod*))Sorting_QuickSort_TisLightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_mD7019ED48D20810C1169430283118F96945E9450_gshared)(___0_data, ___1_start, ___2_end, ___3_compare, method);
}
inline void WorkSlice_1_Sort_m7EF532E936D55845DAAC606C0A214FE48EBF8584 (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___0_compare, const RuntimeMethod* method)
{
	((  void (*) (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87*, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821*, const RuntimeMethod*))WorkSlice_1_Sort_m7EF532E936D55845DAAC606C0A214FE48EBF8584_gshared)(__this, ___0_compare, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetTarget_mE0AF851834410E2AEA6285B2497751570236C794 (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GCHandle_SetRef_m89BDD13EED80A828682061BEF6D21F334AE45FC7_inline (intptr_t ___0_handle, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t GCHandle_GetTargetHandle_mE33A9DC8A8FA880F9CAA057300E28BC8AE743CED (RuntimeObject* ___0_obj, intptr_t ___1_handle, int32_t ___2_type, const RuntimeMethod* method) ;
inline EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* EqualityComparer_1_CreateComparer_mFA29AAFB8E37E401F19B2D5CC3E3C877B467E449 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mFA29AAFB8E37E401F19B2D5CC3E3C877B467E449_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF (intptr_t ___0_value, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 23794
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_get_value_m130C88D03ABADB576A908E2E26FE90E24881F7DB_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0)), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		return;
	}
}
// Method Definition Index: 23795
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_set_value_m09FF3C49735C8ECA8ACA4572044EA393D95C6376_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, Il2CppFullySharedGenericAny ___0_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? ___0_value : &___0_value), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), L_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		return;
	}
}
// Method Definition Index: 23796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1__ctor_mA616936A4E10317580AE921071D36637ED0A3FE9_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	memset(V_0, 0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(L_0, V_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, bool >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 2)), il2cpp_rgctx_method(method->klass->rgctx_data, 2), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_0: *(void**)L_0), (bool)0);
		return;
	}
}
// Method Definition Index: 23797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1__ctor_m863FDCA6A4AE26E8D21738715A6E337BB7D5FDD8_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, Il2CppFullySharedGenericAny ___0_value, bool ___1_overrideState, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VolumeParameter__ctor_m1A76B3C6C284C912F55F7C7E6EF21A18AF3930D2((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, NULL);
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? ___0_value : &___0_value), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), L_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		bool L_1 = ___1_overrideState;
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		VirtualActionInvoker1< bool >::Invoke(6, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, L_1);
		return;
	}
}
// Method Definition Index: 23798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_Interp_m0CA46FB75295800D8B2A7C02F66F7DDD9384D23C_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* ___0_from, VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* ___1_to, float ___2_t, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* L_0 = ___0_from;
		NullCheck(((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)IsInstClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)IsInstClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))), (Il2CppFullySharedGenericAny*)L_1);
		VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* L_2 = ___1_to;
		NullCheck(((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)IsInstClass((RuntimeObject*)L_2, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)IsInstClass((RuntimeObject*)L_2, il2cpp_rgctx_data(method->klass->rgctx_data, 0))), (Il2CppFullySharedGenericAny*)L_3);
		float L_4 = ___2_t;
		VirtualActionInvoker3Invoker< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, float >::Invoke(16, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_1: *(void**)L_1), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_3: *(void**)L_3), L_4);
		return;
	}
}
// Method Definition Index: 23799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_Interp_mA5DD59296A4481DBEC4ACDE08B11497E0838684F_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, Il2CppFullySharedGenericAny ___0_from, Il2CppFullySharedGenericAny ___1_to, float ___2_t, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	const Il2CppFullySharedGenericAny L_2 = L_1;
	//<source_info:<no-source>:1>
	VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* G_B2_0 = NULL;
	VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* G_B1_0 = NULL;
	Il2CppFullySharedGenericAny G_B3_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	memset(G_B3_0, 0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* G_B3_1 = NULL;
	{
		float L_0 = ___2_t;
		if ((((float)L_0) > ((float)(0.0f))))
		{
			G_B2_0 = ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)__this);
			goto IL_000c;
		}
		G_B1_0 = ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)__this);
	}
	{
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? ___0_from : &___0_from), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(G_B3_0, L_1, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		G_B3_1 = ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)G_B1_0);
		goto IL_000d;
	}

IL_000c:
	{
		il2cpp_codegen_memcpy(L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? ___1_to : &___1_to), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(G_B3_0, L_2, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		G_B3_1 = ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)G_B2_0);
	}

IL_000d:
	{
		NullCheck(G_B3_1);
		il2cpp_codegen_write_instance_field_data(G_B3_1, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), G_B3_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		return;
	}
}
// Method Definition Index: 23800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_Override_m7C1B4B87F845CEF17B9FE1DC7C476741E2AA73C2_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, Il2CppFullySharedGenericAny ___0_x, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		VirtualActionInvoker1< bool >::Invoke(6, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, (bool)1);
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? ___0_x : &___0_x), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), L_0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		return;
	}
}
// Method Definition Index: 23801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_SetValue_mC22AF6C46073698212DA5E411F582D8D1A4F2589_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* ___0_parameter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* L_0 = ___0_parameter;
		il2cpp_codegen_memcpy(L_1, il2cpp_codegen_get_instance_field_data_pointer(((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)CastclassClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))), il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0)), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), L_1, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		return;
	}
}
// Method Definition Index: 23802
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VolumeParameter_1_GetHashCode_m67709A9D28380EB1F99B0D0877445D25828E5891_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	void* L_9 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	const Il2CppFullySharedGenericAny L_8 = L_4;
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	bool V_1 = false;
	Il2CppFullySharedGenericAny V_2 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	memset(V_2, 0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	{
		V_0 = ((int32_t)17);
		int32_t L_0 = V_0;
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_1;
		L_1 = VirtualFuncInvoker0< bool >::Invoke(5, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		V_1 = L_1;
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.boolean_class);
		int32_t L_2;
		L_2 = Boolean_GetHashCode_mEDB6904770C962BAF4510E5D24F08083C33900E3((&V_1), NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)23))), L_2));
		EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* L_3;
		L_3 = ((  EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, __this, (Il2CppFullySharedGenericAny*)L_4);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_2, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(L_5, V_2, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		NullCheck(L_3);
		bool L_6;
		L_6 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(8, L_3, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_4: *(void**)L_4), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_5: *(void**)L_5));
		if (L_6)
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_7 = V_0;
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, __this, (Il2CppFullySharedGenericAny*)L_8);
		il2cpp_codegen_memcpy(V_2, L_8, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		Il2CppConstrainedCallData L_10;
		Il2CppMethodPointer L_11 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1), il2cpp_rgctx_method(method->klass->rgctx_data, 9), (void*)(Il2CppFullySharedGenericAny*)V_2, &L_10, L_9);
		typedef int32_t ( *func_L_12)(void*,const RuntimeMethod*);
		int32_t L_13 = ((func_L_12)L_11)(L_10.thisPtr,L_10.method);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)23))), L_13));
	}

IL_004c:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 23803
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* VolumeParameter_1_ToString_m1DC4E78F08D48194AF38E9ED9EB63B4C4195E86E_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA5E215A6DBE803E908043576B18C4FAD26AD44F7);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, __this, (Il2CppFullySharedGenericAny*)L_0);
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1), L_0);
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_2;
		L_2 = VirtualFuncInvoker0< bool >::Invoke(5, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_defaults.boolean_class, &L_3);
		String_t* L_5;
		L_5 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralA5E215A6DBE803E908043576B18C4FAD26AD44F7, L_1, L_4, NULL);
		return L_5;
	}
}
// Method Definition Index: 23804
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_op_Equality_mFB9A5ACACD63E673940ABCCD71BFBCF5939514B3_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* ___0_lhs, Il2CppFullySharedGenericAny ___1_rhs, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	void* L_8 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1)));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	const Il2CppFullySharedGenericAny L_5 = L_2;
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	memset(V_0, 0, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_0 = ___0_lhs;
		if (!L_0)
		{
			goto IL_002b;
		}
	}
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_1 = ___0_lhs;
		NullCheck(L_1);
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, L_1, (Il2CppFullySharedGenericAny*)L_2);
		bool L_3 = il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1), L_2);
		if (!L_3)
		{
			goto IL_002b;
		}
	}
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_4 = ___0_lhs;
		NullCheck(L_4);
		VirtualActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(14, L_4, (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_0, L_5, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1)) ? ___1_rhs : &___1_rhs), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		RuntimeObject* L_7 = Box(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1), L_6);
		Il2CppConstrainedCallData L_9;
		Il2CppMethodPointer L_10 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 10), (void*)(Il2CppFullySharedGenericAny*)V_0, &L_9, L_8);
		typedef bool ( *func_L_11)(void*,RuntimeObject*,const RuntimeMethod*);
		bool L_12 = ((func_L_11)L_10)(L_9.thisPtr, L_7,L_9.method);
		return L_12;
	}

IL_002b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 23805
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_op_Inequality_m8551AFE47546E9FE859077FB75033B4DABB36AA8_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* ___0_lhs, Il2CppFullySharedGenericAny ___1_rhs, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_0 = ___0_lhs;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1)) ? ___1_rhs : &___1_rhs), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		bool L_2;
		L_2 = InvokerFuncInvoker2< bool, VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 11)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 11), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1)) ? L_1: *(void**)L_1));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 23806
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_Equals_mE6CB1D07EC2DE1DE825EB7AE097CA54AB980218F_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* ___0_other, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		return (bool)0;
	}

IL_0005:
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_1 = ___0_other;
		if ((!(((RuntimeObject*)(VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)__this) == ((RuntimeObject*)(VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)L_1))))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_000b:
	{
		EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* L_2;
		L_2 = ((  EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		il2cpp_codegen_memcpy(L_3, il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0)), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_4 = ___0_other;
		il2cpp_codegen_memcpy(L_5, il2cpp_codegen_get_instance_field_data_pointer(L_4, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0)), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		NullCheck(L_2);
		bool L_6;
		L_6 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(8, L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_3: *(void**)L_3), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_5: *(void**)L_5));
		return L_6;
	}
}
// Method Definition Index: 23807
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_Equals_m72DBE726E1E91E1E6FBB9463C65FB181504FAC57_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		bool L_1;
		L_1 = ((  bool (*) (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*, VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)))(__this, ((VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)IsInstClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return L_1;
	}
}
// Method Definition Index: 23808
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* VolumeParameter_1_Clone_m6C0CD60546286A326AA2237501E028E5E537DBF5_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 14)), il2cpp_rgctx_method(method->klass->rgctx_data, 14), (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, (Il2CppFullySharedGenericAny*)L_0);
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_1;
		L_1 = VirtualFuncInvoker0< bool >::Invoke(5, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_2 = (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0));
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, bool >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 2)), il2cpp_rgctx_method(method->klass->rgctx_data, 2), L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1)) ? L_0: *(void**)L_0), L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 23809
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_op_Explicit_m06E2D8024C6E6B043D67E524AD2FB6A0EA25BF4F_gshared (VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* ___0_prop, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
	//<source_info:<no-source>:1>
	{
		VolumeParameter_1_tB1EA9187ACF6A0B2CAC6CF51C310D670594DCCD3* L_0 = ___0_prop;
		il2cpp_codegen_memcpy(L_1, il2cpp_codegen_get_instance_field_data_pointer(L_0, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)), SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		il2cpp_codegen_memcpy(il2cppRetVal, L_1, SizeOf_T_t6F7A42E482B273BE8680284FFC0EA16E6A955CD7);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 23794
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VolumeParameter_1_get_value_mE7E0EA96FE2D033B78B3388805C197F6E3D2CB4A_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 23795
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_set_value_m2430F79CB005B691569C13BBEF245ACB7A1E173A_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->___m_Value = L_0;
		return;
	}
}
// Method Definition Index: 23796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1__ctor_mCE7BAC371D0CC606A8FC2DFCF878B3815A20A31D_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		int32_t L_0 = V_0;
		VolumeParameter_1__ctor_m70508BCB9F5865418A150EE673A6427870A59465(__this, L_0, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 2));
		return;
	}
}
// Method Definition Index: 23797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1__ctor_m70508BCB9F5865418A150EE673A6427870A59465_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, int32_t ___0_value, bool ___1_overrideState, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VolumeParameter__ctor_m1A76B3C6C284C912F55F7C7E6EF21A18AF3930D2((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, NULL);
		int32_t L_0 = ___0_value;
		__this->___m_Value = L_0;
		bool L_1 = ___1_overrideState;
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		VirtualActionInvoker1< bool >::Invoke(6, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, L_1);
		return;
	}
}
// Method Definition Index: 23798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_Interp_mA64C4D08ADCFE7F0BBFC1C4338988FF5007625F7_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* ___0_from, VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* ___1_to, float ___2_t, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* L_0 = ___0_from;
		NullCheck(((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)IsInstClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		int32_t L_1;
		L_1 = VirtualFuncInvoker0< int32_t >::Invoke(14, ((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)IsInstClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* L_2 = ___1_to;
		NullCheck(((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)IsInstClass((RuntimeObject*)L_2, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		int32_t L_3;
		L_3 = VirtualFuncInvoker0< int32_t >::Invoke(14, ((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)IsInstClass((RuntimeObject*)L_2, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		float L_4 = ___2_t;
		VirtualActionInvoker3< int32_t, int32_t, float >::Invoke(16, __this, L_1, L_3, L_4);
		return;
	}
}
// Method Definition Index: 23799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_Interp_m5460772FCEE7252515E21F9463C3326C14BFEB8B_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, int32_t ___0_from, int32_t ___1_to, float ___2_t, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* G_B2_0 = NULL;
	VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* G_B3_1 = NULL;
	{
		float L_0 = ___2_t;
		if ((((float)L_0) > ((float)(0.0f))))
		{
			G_B2_0 = __this;
			goto IL_000c;
		}
		G_B1_0 = __this;
	}
	{
		int32_t L_1 = ___0_from;
		G_B3_0 = L_1;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_000c:
	{
		int32_t L_2 = ___1_to;
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		NullCheck(G_B3_1);
		G_B3_1->___m_Value = G_B3_0;
		return;
	}
}
// Method Definition Index: 23800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_Override_m091F07F79726EAF45D71CEFF91E51A11812B59F3_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, int32_t ___0_x, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		VirtualActionInvoker1< bool >::Invoke(6, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, (bool)1);
		int32_t L_0 = ___0_x;
		__this->___m_Value = L_0;
		return;
	}
}
// Method Definition Index: 23801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VolumeParameter_1_SetValue_m6597CAE3F4B89DC94E15D73E01A54ABF4EB1D5CE_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* ___0_parameter, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72* L_0 = ___0_parameter;
		NullCheck(((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)CastclassClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		int32_t L_1 = ((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)CastclassClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0)))->___m_Value;
		__this->___m_Value = L_1;
		return;
	}
}
// Method Definition Index: 23802
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VolumeParameter_1_GetHashCode_mB92F585C7A157ED9D17CB1BF5DBDBFE151860C84_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	bool V_1 = false;
	int32_t V_2 = 0;
	{
		V_0 = ((int32_t)17);
		int32_t L_0 = V_0;
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_1;
		L_1 = VirtualFuncInvoker0< bool >::Invoke(5, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		V_1 = L_1;
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.boolean_class);
		int32_t L_2;
		L_2 = Boolean_GetHashCode_mEDB6904770C962BAF4510E5D24F08083C33900E3((&V_1), NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)23))), L_2));
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_3;
		L_3 = EqualityComparer_1_get_Default_mC0B29FC6AFED03D8A30BE41AC4BEC15DCF6AA9F8_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		int32_t L_4;
		L_4 = VirtualFuncInvoker0< int32_t >::Invoke(14, __this);
		il2cpp_codegen_initobj((&V_2), sizeof(int32_t));
		int32_t L_5 = V_2;
		NullCheck(L_3);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_3, L_4, L_5);
		if (L_6)
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = VirtualFuncInvoker0< int32_t >::Invoke(14, __this);
		V_2 = L_8;
		int32_t L_9;
		L_9 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&V_2), NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)23))), L_9));
	}

IL_004c:
	{
		int32_t L_10 = V_0;
		return L_10;
	}
}
// Method Definition Index: 23803
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* VolumeParameter_1_ToString_m07DC5211B941BB2A168731CE06FE045018BD4169_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA5E215A6DBE803E908043576B18C4FAD26AD44F7);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(14, __this);
		int32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 1), &L_1);
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_3;
		L_3 = VirtualFuncInvoker0< bool >::Invoke(5, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_4 = L_3;
		RuntimeObject* L_5 = Box(il2cpp_defaults.boolean_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralA5E215A6DBE803E908043576B18C4FAD26AD44F7, L_2, L_5, NULL);
		return L_6;
	}
}
// Method Definition Index: 23804
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_op_Equality_m5FD3D0F9F083CA946C24FEE5315560B181F1D4C0_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_lhs, int32_t ___1_rhs, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_0 = ___0_lhs;
		if (!L_0)
		{
			goto IL_002b;
		}
	}
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_1 = ___0_lhs;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = VirtualFuncInvoker0< int32_t >::Invoke(14, L_1);
	}
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_3 = ___0_lhs;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = VirtualFuncInvoker0< int32_t >::Invoke(14, L_3);
		V_0 = L_4;
		int32_t L_5 = ___1_rhs;
		int32_t L_6 = L_5;
		RuntimeObject* L_7 = Box(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1), &L_6);
		Il2CppFakeBox<int32_t> L_8(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1), V_0);
		bool L_9;
		L_9 = Enum_Equals_m96B1058BA6312E23F31A5FBF594E96EB692EAF4E((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_8), L_7, NULL);
		return L_9;
	}

IL_002b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 23805
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_op_Inequality_m56D5EF2C851D135927A1794452BB8BA7F899B0C3_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_lhs, int32_t ___1_rhs, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_0 = ___0_lhs;
		int32_t L_1 = ___1_rhs;
		bool L_2;
		L_2 = VolumeParameter_1_op_Equality_m5FD3D0F9F083CA946C24FEE5315560B181F1D4C0(L_0, L_1, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 11));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 23806
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_Equals_m8ED6C08D00A26D41DD9529DE530240A83EAF381E_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		return (bool)0;
	}

IL_0005:
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_1 = ___0_other;
		if ((!(((RuntimeObject*)(VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)__this) == ((RuntimeObject*)(VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)L_1))))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_000b:
	{
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_2;
		L_2 = EqualityComparer_1_get_Default_mC0B29FC6AFED03D8A30BE41AC4BEC15DCF6AA9F8_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		int32_t L_3 = __this->___m_Value;
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_4 = ___0_other;
		NullCheck(L_4);
		int32_t L_5 = L_4->___m_Value;
		NullCheck(L_2);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_2, L_3, L_5);
		return L_6;
	}
}
// Method Definition Index: 23807
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VolumeParameter_1_Equals_mAE49ADEC70E22AEC8A1A22015CB8206B065F90AD_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		bool L_1;
		L_1 = VolumeParameter_1_Equals_m8ED6C08D00A26D41DD9529DE530240A83EAF381E(__this, ((VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)IsInstClass((RuntimeObject*)L_0, il2cpp_rgctx_data(method->klass->rgctx_data, 0))), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return L_1;
	}
}
// Method Definition Index: 23808
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* VolumeParameter_1_Clone_m4F59043C242AE03A381FA85D21CCF35EEA9C3865_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		int32_t L_0;
		L_0 = VolumeParameter_GetValue_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE40AE16776FF3B42C9A2683D870A5648BACFC0D6((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		NullCheck((VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		bool L_1;
		L_1 = VirtualFuncInvoker0< bool >::Invoke(5, (VolumeParameter_t95994C89644D2CC4C11F666571492420D16BED72*)__this);
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_2 = (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0));
		VolumeParameter_1__ctor_m70508BCB9F5865418A150EE673A6427870A59465(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 2));
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 23809
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VolumeParameter_1_op_Explicit_m88A520EA8A8EDBA70AD9BCABEDEA00D829D544CF_gshared (VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* ___0_prop, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VolumeParameter_1_t049BE85379CBBDCCBB6793EA2A5E5A1D519E0C86* L_0 = ___0_prop;
		NullCheck(L_0);
		int32_t L_1 = L_0->___m_Value;
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 3497
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m2DF2E9240755AD44CD007215336336988FB94970_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = ___0_target;
		WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E(__this, L_0, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 1));
		return;
	}
}
// Method Definition Index: 3498
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, bool ___1_trackResurrection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		bool L_0 = ___1_trackResurrection;
		__this->___trackResurrection = L_0;
		bool L_1 = ___1_trackResurrection;
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_0014;
	}

IL_0013:
	{
		G_B3_0 = 1;
	}

IL_0014:
	{
		V_0 = (int32_t)G_B3_0;
		Il2CppSharedGenericObject* L_2 = ___0_target;
		int32_t L_3 = V_0;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_4;
		L_4 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC((RuntimeObject*)L_2, L_3, NULL);
		__this->___handle = L_4;
		return;
	}
}
// Method Definition Index: 3499
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m26B6C20B9417150055843B01C492BE853F888ED6_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_0014:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		NullCheck(L_2);
		bool L_3;
		L_3 = SerializationInfo_GetBoolean_m8335F8E11B572AB6B5BF85A9355D6888D5847EF5(L_2, _stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7, NULL);
		__this->___trackResurrection = L_3;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->klass->rgctx_data, 3)) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		NullCheck(L_4);
		RuntimeObject* L_7;
		L_7 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_4, _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0, L_6, NULL);
		V_0 = L_7;
		bool L_8 = __this->___trackResurrection;
		if (L_8)
		{
			goto IL_0046;
		}
	}
	{
		G_B5_0 = 0;
		goto IL_0047;
	}

IL_0046:
	{
		G_B5_0 = 1;
	}

IL_0047:
	{
		V_1 = (int32_t)G_B5_0;
		RuntimeObject* L_9 = V_0;
		int32_t L_10 = V_1;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_11;
		L_11 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC(L_9, L_10, NULL);
		__this->___handle = L_11;
		return;
	}
}
// Method Definition Index: 3500
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1_GetObjectData_m12FA42C2A3928DF070B0FB1604D23E96E650100B_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		bool L_3 = __this->___trackResurrection;
		NullCheck(L_2);
		SerializationInfo_AddValue_mC52253CB19C98F82A26E32C941F8F20E106D4C0D(L_2, _stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7, L_3, NULL);
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_4 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		bool L_5;
		L_5 = GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline(L_4, NULL);
		if (!L_5)
		{
			goto IL_0043;
		}
	}
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_6 = ___0_info;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_7 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		RuntimeObject* L_8;
		L_8 = GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline(L_7, NULL);
		NullCheck(L_6);
		SerializationInfo_AddValue_m28FE9B110F21DDB8FF5F5E35A0EABD659DB22C2F(L_6, _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0, L_8, NULL);
		return;
	}

IL_0043:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		NullCheck(L_9);
		SerializationInfo_AddValue_m28FE9B110F21DDB8FF5F5E35A0EABD659DB22C2F(L_9, _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0, NULL, NULL);
		return;
	}
}
// Method Definition Index: 3501
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1_SetTarget_mDE725E23AF954B676DFE5B39328B17786CBE09F9_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_0 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		Il2CppSharedGenericObject* L_1 = ___0_target;
		GCHandle_set_Target_m1DB05E14910747D2A74ACEB4C48028C4AEBFCF3D_inline(L_0, (RuntimeObject*)L_1, NULL);
		return;
	}
}
// Method Definition Index: 3502
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WeakReference_1_TryGetTarget_mBE4F373E7AC9285E659FCC2CE05E7820CF84C814_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject** ___0_target, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_0 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		bool L_1;
		L_1 = GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline(L_0, NULL);
		if (L_1)
		{
			goto IL_0016;
		}
	}
	{
		Il2CppSharedGenericObject** L_2 = ___0_target;
		il2cpp_codegen_initobj(L_2, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}

IL_0016:
	{
		Il2CppSharedGenericObject** L_3 = ___0_target;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_4 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		RuntimeObject* L_5;
		L_5 = GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline(L_4, NULL);
		*(Il2CppSharedGenericObject**)L_3 = ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_5, il2cpp_rgctx_data(method->klass->rgctx_data, 0)));
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_5, il2cpp_rgctx_data(method->klass->rgctx_data, 0))));
		Il2CppSharedGenericObject** L_6 = ___0_target;
		Il2CppSharedGenericObject* L_7 = (*(Il2CppSharedGenericObject**)L_6);
		return (bool)((!(((RuntimeObject*)(Il2CppSharedGenericObject*)L_7) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
	}
}
// Method Definition Index: 3503
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1_Finalize_m7E4CC88F283E425189EB1C8BC510906088E6FBE8_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{
				NullCheck((RuntimeObject*)__this);
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2((RuntimeObject*)__this, NULL);
				return;
			}
		});
		try
		{
			GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_0 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
			GCHandle_Free_m1320A260E487EB1EA6D95F9E54BFFCB5A4EF83A3(L_0, NULL);
			goto IL_0014;
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30634
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where__ctor_mB320D4A16B60EB5C93B756BC6EF4F58C18738A0D_gshared (Where_t8628A3898F012DDE1FB9931908812596C248A533* __this, WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* ___0_observable, RuntimeObject* ___1_observer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* L_0 = ___0_observable;
		__this->___m_Observable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Observable), (void*)L_0);
		RuntimeObject* L_1 = ___1_observer;
		__this->___m_Observer = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Observer), (void*)L_1);
		return;
	}
}
// Method Definition Index: 30635
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where_OnCompleted_mBDF275E4C7E455518FBC33295215138125E14D85_gshared (Where_t8628A3898F012DDE1FB9931908812596C248A533* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return;
	}
}
// Method Definition Index: 30636
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where_OnError_m62966161E2258B196B520332D33C0B12FA5228ED_gshared (Where_t8628A3898F012DDE1FB9931908812596C248A533* __this, Exception_t* ___0_error, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		Exception_t* L_0 = ___0_error;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogException_mAB3F4DC7297ED8FBB49DAA718B70E59A6B0171B0(L_0, NULL);
		return;
	}
}
// Method Definition Index: 30637
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where_OnNext_m8C7FC535D8E0CBDF9E062A9EE4E3F946F4F59688_gshared (Where_t8628A3898F012DDE1FB9931908812596C248A533* __this, Il2CppSharedGenericObject* ___0_evt, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* L_0 = __this->___m_Observable;
		NullCheck(L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = L_0->___m_Predicate;
		Il2CppSharedGenericObject* L_2 = ___0_evt;
		NullCheck(L_1);
		bool L_3;
		L_3 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_4 = __this->___m_Observer;
		Il2CppSharedGenericObject* L_5 = ___0_evt;
		NullCheck(L_4);
		InterfaceActionInvoker1< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_4, L_5);
	}

IL_001f:
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30634
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where__ctor_m1005F36B2810D6C9BAEA784E3978689A96EB7347_gshared (Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C* __this, WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816* ___0_observable, RuntimeObject* ___1_observer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816* L_0 = ___0_observable;
		__this->___m_Observable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Observable), (void*)L_0);
		RuntimeObject* L_1 = ___1_observer;
		__this->___m_Observer = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Observer), (void*)L_1);
		return;
	}
}
// Method Definition Index: 30635
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where_OnCompleted_m616C74C91F79C9E2AC50707A678EB9E1FE72EB1C_gshared (Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return;
	}
}
// Method Definition Index: 30636
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where_OnError_m856337670C3AEAE4C7F09DA64E3328FF8834431A_gshared (Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C* __this, Exception_t* ___0_error, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		Exception_t* L_0 = ___0_error;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogException_mAB3F4DC7297ED8FBB49DAA718B70E59A6B0171B0(L_0, NULL);
		return;
	}
}
// Method Definition Index: 30637
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Where_OnNext_mA0CF021050C0C4674B3F473DB08E0A7F15D8DEF3_gshared (Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C* __this, Il2CppFullySharedGenericAny ___0_evt, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TValue_t646830852B65DBDC12DCC4F9FEFADE171F489ABE = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_TValue_t646830852B65DBDC12DCC4F9FEFADE171F489ABE);
	const Il2CppFullySharedGenericAny L_5 = L_2;
	//<source_info:<no-source>:1>
	{
		WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816* L_0 = __this->___m_Observable;
		NullCheck(L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = L_0->___m_Predicate;
		il2cpp_codegen_memcpy(L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4)) ? ___0_evt : &___0_evt), SizeOf_TValue_t646830852B65DBDC12DCC4F9FEFADE171F489ABE);
		NullCheck(L_1);
		bool L_3;
		L_3 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)), il2cpp_rgctx_method(method->klass->rgctx_data, 5), L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4)) ? L_2: *(void**)L_2));
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_4 = __this->___m_Observer;
		il2cpp_codegen_memcpy(L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4)) ? ___0_evt : &___0_evt), SizeOf_TValue_t646830852B65DBDC12DCC4F9FEFADE171F489ABE);
		NullCheck(L_4);
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4)) ? L_5: *(void**)L_5));
	}

IL_001f:
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55633
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55634
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereArrayIterator_1_Clone_mE31EE28C8C3AF73A465E9182B4EE6DA783E0DCC8_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* L_2 = (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_2;
	}
}
// Method Definition Index: 55635
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m2CC945527E27709DF2A77749EF065B340B1DAABF_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Il2CppSharedGenericObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_6 = __this->___predicate;
		Il2CppSharedGenericObject* L_7 = V_0;
		NullCheck(L_6);
		bool L_8;
		L_8 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_6, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		Il2CppSharedGenericObject* L_9 = V_0;
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_9);
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->___source;
		NullCheck(L_11);
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		if ((((int32_t)L_10) < ((int32_t)L_12)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55637
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mACF36D740BA7870CDEF62F71205CC9B7AA921FCB_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_2 = ___0_predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_3;
		L_3 = Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* L_4 = (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55633
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_mD8BDE04F9897AAED299EE4DC32BF3879F2CBB668_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		return;
	}
}
// Method Definition Index: 55634
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereArrayIterator_1_Clone_m1D80001794E47D2DF00A77273FD71D61987E8A44_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* L_2 = (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
// Method Definition Index: 55635
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m42FC055181A1CDD12BBB46A9EE9ED76C6048BA07_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	const Il2CppFullySharedGenericAny L_9 = L_4;
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	memset(V_0, 0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1));
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		int32_t L_2 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck(L_1);
		int32_t L_3 = L_2;
		il2cpp_codegen_memcpy(L_4, (L_1)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		il2cpp_codegen_memcpy(V_0, L_4, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		int32_t L_5 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), ((int32_t)il2cpp_codegen_add(L_5, 1)));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_7, V_0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		NullCheck(L_6);
		bool L_8;
		L_8 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 8)), il2cpp_rgctx_method(method->klass->rgctx_data, 8), L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7)) ? L_7: *(void**)L_7));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		il2cpp_codegen_memcpy(L_9, V_0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),2), L_9, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_11);
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		if ((((int32_t)L_10) < ((int32_t)L_12)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55637
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mB2C59E78355E518D359A6D5035BCD6254337B84E_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)))(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* L_4 = (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55633
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m0C3CAA1BDBAA7573FC25AD65F502E6C666B089E7_gshared (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* __this, ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_mC38D09ED8D96D1D64B7C357F04D5569F8231837F((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55634
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* WhereArrayIterator_1_Clone_m767DC982B02BD1FDDC6A1FAD6A190EE3407D485C_gshared (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* L_0 = __this->___source;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = __this->___predicate;
		WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* L_2 = (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m0C3CAA1BDBAA7573FC25AD65F502E6C666B089E7(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)L_2;
	}
}
// Method Definition Index: 55635
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m255B3B298F9DC126EB9FB461EA999CA9B6B1C008_gshared (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_6 = __this->___predicate;
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_7 = V_0;
		NullCheck(L_6);
		bool L_8;
		L_8 = Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_inline(L_6, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_9 = V_0;
		((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current = L_9;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CnameU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CnameU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3ClayoutU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3ClayoutU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CvariantsU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CvariantsU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CuseStateFromU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CdisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CshortDisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CusagesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CaliasesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CprocessorsU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* L_11 = __this->___source;
		NullCheck(L_11);
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		if ((((int32_t)L_10) < ((int32_t)L_12)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55637
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mB418557CB00628405A4F08B048C813863E92BF49_gshared (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* __this, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ControlItemU5BU5D_t7798E8B7C7F58B8F6D13B567539CD82E962C7104* L_0 = __this->___source;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = __this->___predicate;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_2 = ___0_predicate;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_3;
		L_3 = Enumerable_CombinePredicates_TisControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_mD2B49AA9212177D38B017D33CCE9233E3E5AA947(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A* L_4 = (WhereArrayIterator_1_tA2D7AF8CFAD16C5282CEC426637A65900045C22A*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m0C3CAA1BDBAA7573FC25AD65F502E6C666B089E7(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55627
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4_gshared (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55628
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereEnumerableIterator_1_Clone_m1EFA74084C05125BC3322378CD76FC73ECB31A05_gshared (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_2 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_2;
	}
}
// Method Definition Index: 55629
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m63472DE73AC8C8DE22EA92901299B97F75827FC8_gshared (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
// Method Definition Index: 55630
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m2E1815DECA351DE8EC09BCD76F9DC8ADED85C166_gshared (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6;
		L_6 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_10 = V_1;
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55632
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_mCD8E919776DD2446498251958D3BBFFADD79D829_gshared (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_2 = ___0_predicate;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_3;
		L_3 = Enumerable_CombinePredicates_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_mF2B98D83EF1AA959DC98FAC180FA2C16DB6E21BB(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_4 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55627
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55628
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereEnumerableIterator_1_Clone_m147E8C6841D1F56383B65AB9442D5F8572E0C4A0_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_2 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_2;
	}
}
// Method Definition Index: 55629
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_mB5CFE2E915EAE2A54092B3BF72CF0AE757569B0C_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
// Method Definition Index: 55630
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m3E17222A4C6715CC745CCE37FDA4B1F349DDA260_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		Il2CppSharedGenericObject* L_6;
		L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		Il2CppSharedGenericObject* L_10 = V_1;
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_10);
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55632
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m6827EA1DFE793999773F608F522A3DAC4E550561_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_2 = ___0_predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_3;
		L_3 = Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_4 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55627
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m2DD2BB86C5517EDD8C051BBF8CE38C43D712A8D6_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		return;
	}
}
// Method Definition Index: 55628
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereEnumerableIterator_1_Clone_m0317D203B88386A9A479C72FA9D62763FD0A91D3_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_2 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
// Method Definition Index: 55629
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m2583FECFDC8EDFE66C959C7C386F99E287C5763E_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), (RuntimeObject*)NULL);
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 8)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
// Method Definition Index: 55630
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m1A18D4050C069B6C4310DAB9857281E37DCB2C69_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	const Il2CppFullySharedGenericAny L_10 = L_6;
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	memset(V_1, 0, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_4);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1), 2);
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck(L_5);
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5, (Il2CppFullySharedGenericAny*)L_6);
		il2cpp_codegen_memcpy(V_1, L_6, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_8, V_1, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		NullCheck(L_7);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 12)), il2cpp_rgctx_method(method->klass->rgctx_data, 12), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		il2cpp_codegen_memcpy(L_10, V_1, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),2), L_10, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55632
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_mC623267514B4299E409A01161DBBDA5362CEDFC2_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)))(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_4 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55627
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m52C3E4AB52EE018DFBE97FF259F9CCBF2F2498E0_gshared (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, RuntimeObject* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_mC38D09ED8D96D1D64B7C357F04D5569F8231837F((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55628
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* WhereEnumerableIterator_1_Clone_m7059DF9CAD10807CC79AE5D418C1AD5CD159CD54_gshared (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* L_2 = (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m52C3E4AB52EE018DFBE97FF259F9CCBF2F2498E0(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)L_2;
	}
}
// Method Definition Index: 55629
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_mCDE0A609D15D1E289BFF3D0365ECB1E4127E0A21_gshared (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
		Iterator_1_Dispose_m9B46AEDB129561EFB4315D054CB6C4FF811B03D8((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
// Method Definition Index: 55630
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m77B9F07A83494671A43EE648AFADF98A3FDFC19C_gshared (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_6;
		L_6 = InterfaceFuncInvoker0< ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_7 = __this->___predicate;
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_10 = V_1;
		((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CnameU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CnameU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3ClayoutU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3ClayoutU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CvariantsU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CvariantsU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CuseStateFromU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CdisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CshortDisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CusagesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CaliasesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CprocessorsU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55632
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m0238B111A5822E8D18803D60C114CD5EB439D4C0_gshared (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* __this, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = __this->___predicate;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_2 = ___0_predicate;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_3;
		L_3 = Enumerable_CombinePredicates_TisControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_mD2B49AA9212177D38B017D33CCE9233E3E5AA947(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B* L_4 = (WhereEnumerableIterator_1_t67E0670A64E01F5760CD5486302DA145FA5BB82B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m52C3E4AB52EE018DFBE97FF259F9CCBF2F2498E0(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55638
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55639
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereListIterator_1_Clone_mD1DC0907762FD59A96CDD4DDC5DF1C2BB20818A8_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* L_2 = (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_2;
	}
}
// Method Definition Index: 55640
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mA5874C778A5BE1094329ADAA040BFD8EDD1FBCE0_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_4;
		L_4 = List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_5 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		Il2CppSharedGenericObject* L_6;
		L_6 = Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		Il2CppSharedGenericObject* L_10 = V_1;
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_10);
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_11 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25(L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55642
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_m14EE1FAA82AE63BE42B030236807F4DA4B8D5520_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_2 = ___0_predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_3;
		L_3 = Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* L_4 = (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55638
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mC075454926AF320E4679335A1B81D3F56ACEFC0C_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		return;
	}
}
// Method Definition Index: 55639
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereListIterator_1_Clone_mAA3ED56493E5FF2F49FE37EB7CDF6C0A957698B5_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* L_2 = (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
// Method Definition Index: 55640
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mB5E4EB089AD8CF7156B8972C7FB61739C466ED5E_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11));
	const uint32_t SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	const Il2CppFullySharedGenericAny L_9 = L_5;
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_4 = alloca(SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	memset(V_1, 0, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_3 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		InvokerActionInvoker1< Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 7)), il2cpp_rgctx_method(method->klass->rgctx_data, 7), L_3, (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_4);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_4, SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1), 2);
		goto IL_004e;
	}

IL_002b:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)), il2cpp_rgctx_method(method->klass->rgctx_data, 9), (((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2)))), (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_1, L_5, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_7, V_1, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		NullCheck(L_6);
		bool L_8;
		L_8 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 12)), il2cpp_rgctx_method(method->klass->rgctx_data, 12), L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11)) ? L_7: *(void**)L_7));
		if (!L_8)
		{
			goto IL_004e;
		}
	}
	{
		il2cpp_codegen_memcpy(L_9, V_1, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),2), L_9, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		return (bool)1;
	}

IL_004e:
	{
		bool L_10;
		L_10 = ((  bool (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)))((((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2)))), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_10)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55642
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_mC767815DE2249E70B38D6D172A0C61B028D7A44B_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* L_4 = (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55638
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m5FAFE85609CE304AA9F43211F0AB34D1C6C77F6B_gshared (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* __this, List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* ___0_source, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_mC38D09ED8D96D1D64B7C357F04D5569F8231837F((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 55639
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563* WhereListIterator_1_Clone_m2538DA1E33918A6F9C85A592B44D318CD7FD0B4A_gshared (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* L_0 = __this->___source;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = __this->___predicate;
		WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* L_2 = (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m5FAFE85609CE304AA9F43211F0AB34D1C6C77F6B(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)L_2;
	}
}
// Method Definition Index: 55640
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_m0AB5230508034B9FE3F9D6DC563406174C4E3A84_gshared (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0 L_4;
		L_4 = List_1_GetEnumerator_m37A8F02E3D82B04207F54C6A4D70EFBF2B7E080B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CnameU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CnameU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3ClayoutU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3ClayoutU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CvariantsU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CvariantsU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CuseStateFromU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CdisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CshortDisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CusagesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CaliasesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CprocessorsU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* L_5 = (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0*)(&__this->___enumerator);
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_6;
		L_6 = Enumerator_get_Current_m932259DC5443095A2D7AE244692FBCCD52A92261_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		V_1 = L_6;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_7 = __this->___predicate;
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_10 = V_1;
		((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CnameU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CnameU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3ClayoutU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3ClayoutU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CvariantsU3Ek__BackingField))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CvariantsU3Ek__BackingField))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CuseStateFromU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CdisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CshortDisplayNameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CusagesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CaliasesU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this)->___current))->___U3CprocessorsU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* L_11 = (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_m8784F0F24421DA9476E0E4240A25D7760B24EF46(L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t84977E1F8BF6F5E7E429E5F02E683DAC7F6A9563*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55642
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_mDFCE357B4F203C037C3791178F63D9BAF51E46A9_gshared (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* __this, Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tBF847DD77CE898FDD304012AB5DFBFC15986D8F7* L_0 = __this->___source;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_1 = __this->___predicate;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_2 = ___0_predicate;
		Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* L_3;
		L_3 = Enumerable_CombinePredicates_TisControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD_mD2B49AA9212177D38B017D33CCE9233E3E5AA947(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07* L_4 = (WhereListIterator_1_t4058B113190F2A2488560601700A7E02A3B51D07*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m5FAFE85609CE304AA9F43211F0AB34D1C6C77F6B(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30632
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereObservable_1__ctor_m7DAA4045A205F49CE48D01F29B45AD52AAFD5525_gshared (WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_source;
		__this->___m_Source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___m_Predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 30633
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereObservable_1_Subscribe_mFD871B0B1CA78CF0C93497909D237AC150F782B3_gshared (WhereObservable_1_t1FFDD1DADF220133CF2809DA4B8FBEC91102AFF0* __this, RuntimeObject* ___0_observer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_Source;
		RuntimeObject* L_1 = ___0_observer;
		Where_t8628A3898F012DDE1FB9931908812596C248A533* L_2 = (Where_t8628A3898F012DDE1FB9931908812596C248A533*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4));
		Where__ctor_mB320D4A16B60EB5C93B756BC6EF4F58C18738A0D(L_2, __this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		NullCheck(L_0);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker1< RuntimeObject*, RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 0), L_0, (RuntimeObject*)L_2);
		return L_3;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30632
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereObservable_1__ctor_m6C7B01F3F1790F57E8A6CB4AA4B3C3FF98902286_gshared (WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_source;
		__this->___m_Source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Source), (void*)L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		__this->___m_Predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Predicate), (void*)L_1);
		return;
	}
}
// Method Definition Index: 30633
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereObservable_1_Subscribe_m168CEC0B9EEA35158738902505C40C2DE2D53ED5_gshared (WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816* __this, RuntimeObject* ___0_observer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_Source;
		RuntimeObject* L_1 = ___0_observer;
		Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C* L_2 = (Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4));
		((  void (*) (Where_t04DB031F94FE910A83839B12D2DC5BCACAA6F25C*, WhereObservable_1_tEA716A5FC9C57957678BF073F6DD611E500A5816*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, __this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		NullCheck(L_0);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker1< RuntimeObject*, RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 0), L_0, (RuntimeObject*)L_2);
		return L_3;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mCFD30A36FBFA5C4FDFF9E98B1F93C0817BF96CEB_gshared (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_mBC4240D0284914449BF03A8478CE8478E7C14CEF_gshared (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_0 = __this->___source;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = __this->___predicate;
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* L_3 = (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mCFD30A36FBFA5C4FDFF9E98B1F93C0817BF96CEB(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mF569D6A40F603D92848BFF7EA24086ACFCF0477F_gshared (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_7 = __this->___predicate;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_10 = __this->___selector;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m114FA5C3EBB63116090800B6A7DFFE6FCCBCEE19_gshared (WhereSelectArrayIterator_2_tBED0210C122BEA813622BDB72106CA30826BAE92* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mF15F5CBE5D879FD46EC11C8A9FA1625B851CED70_gshared (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m8C36B9FF1C745DC7FA901213536C802DE058FE2E_gshared (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_0 = __this->___source;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = __this->___predicate;
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* L_3 = (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mF15F5CBE5D879FD46EC11C8A9FA1625B851CED70(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mDB5886E69820BBA2F2FB42A749BDECDF75039EF9_gshared (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_7 = __this->___predicate;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_10 = __this->___selector;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m08C5B66B08B89EA317FBE0BB929A7BD5D8493380_gshared (WhereSelectArrayIterator_2_t4EFC2E492E5A3A400E0E9FCB91D43D7FB7254BAC* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m5BDDAA0BA9083F3F3CBF215938C50A366082D6A8_gshared (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_mDD04F09DA003F2E75E63FA64196F6B1B66433234_gshared (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* L_3 = (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m5BDDAA0BA9083F3F3CBF215938C50A366082D6A8(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mA057F85420877D932E0A2DBEBEF48A482A414436_gshared (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_10 = __this->___selector;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m7B5DF8B9D4D8F3C41FEC2118B7D32E016AB42CD4_gshared (WhereSelectArrayIterator_2_t7BF6EE3FBFA70AF4E56B4EEE56CD35DD4954B9DE* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m20E6415BC3B791E2A14DEC1291C7D32F0E59C503_gshared (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m433AE28ECADE1E81FACEF9C095E0FAAC0CC5CB60_gshared (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* L_3 = (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m20E6415BC3B791E2A14DEC1291C7D32F0E59C503(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mEF13B8793B4E0832702F49E261C5BE421C586A41_gshared (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_10 = __this->___selector;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m900D5679B8749635C764CAAA62260233C80288EC_gshared (WhereSelectArrayIterator_2_t29DBEA459AE5A6C36B5DF72FF1AD52225914E4B3* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m854F57E851CE957E1887DF7D9681E348D5B93BD2_gshared (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* __this, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_m3AEB8421F594BDBE54654227FC3C0CA38C6BBF4B_gshared (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_0 = __this->___source;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = __this->___predicate;
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* L_3 = (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m854F57E851CE957E1887DF7D9681E348D5B93BD2(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mEFA7CF3F6E560DC54AAB7B0FA13B882D60EA1603_gshared (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_7 = __this->___predicate;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_10 = __this->___selector;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mC65A68AD2C4A10EF714C5FB6CEB0212AA4CFB010_gshared (WhereSelectArrayIterator_2_t92DBFDA41E8651F1664DE4C06FC0F5C655E3371E* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m7C9B21069925BAB022EAA5389E494114D7E65E87_gshared (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* __this, NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_mA52CA22A3AFDF09F40D1C1E1948DBCCE89F78FEE_gshared (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_0 = __this->___source;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = __this->___predicate;
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* L_3 = (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m7C9B21069925BAB022EAA5389E494114D7E65E87(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m5C72A74FBF0DAB9F8A9BDD2F132636F9E3DE31AD_gshared (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_7 = __this->___predicate;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_10 = __this->___selector;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		NameAndParametersU5BU5D_tA6C2AC34ACDB1967A7A2CEF4BE1D717ADA695CA2* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m31E411CD2EE19B9F0539F77EAE82ED3F928F99C4_gshared (WhereSelectArrayIterator_2_t79856A3E6C4C7595ADAEFF4DDB183F624D8B926A* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m9372C76DEE0D08D5E2CC6F8E118283B2D9BDE32B_gshared (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* __this, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_m3A84FEEED720091EC565BC721DA4658DFBB0D5E0_gshared (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_0 = __this->___source;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = __this->___predicate;
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* L_3 = (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m9372C76DEE0D08D5E2CC6F8E118283B2D9BDE32B(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m1BE21226DE9BE535E2778B3BCE3DF1BE9BE989A9_gshared (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_7 = __this->___predicate;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_10 = __this->___selector;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mB69E9CE02481A6AC28718CC449A26EC355373A48_gshared (WhereSelectArrayIterator_2_tF8FFB7529EF7368DDC2475753EE412200661F6FB* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mDA0E627B9B299EE9CE197C69DC68EE158E14096F_gshared (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* __this, NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m6FF1B87938D6DE1DD833DE181CA02405E2D41110_gshared (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_0 = __this->___source;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = __this->___predicate;
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* L_3 = (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mDA0E627B9B299EE9CE197C69DC68EE158E14096F(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m87B568CE51ABAA4B26AC7F123BAD907E77167141_gshared (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_7 = __this->___predicate;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_10 = __this->___selector;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		NamedValueU5BU5D_tADD8F1373B88C55F68499688D72C21A97F63303A* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m22539F8236C78FA18152312C36433AF831328912_gshared (WhereSelectArrayIterator_2_t93B12F6F6109443898118C184F67B9D970B3302E* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m75517CAAB359671310703010E1BBE16A3367974C_gshared (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_mA31121083C6DA7A4AE37927AF5AD5C6FFC9EA771_gshared (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* L_3 = (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m75517CAAB359671310703010E1BBE16A3367974C(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m961D56445E616EBEF796BD8C8D100BD156477A28_gshared (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_10 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m36398D8E1F00C37FC6896B199C0C99EF25A7277D_gshared (WhereSelectArrayIterator_2_t1212E02FC05E943063E53277ED74EAA758B68E98* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m7FA46E216E6C6F344CA4F2EFDAED7C1ECB2608C3_gshared (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m3467557D0FA634488D739EEAD4BFBF333EA857D6_gshared (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* L_3 = (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m7FA46E216E6C6F344CA4F2EFDAED7C1ECB2608C3(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m4BCA7A2CBEF1084B57B7065883CE0A9DD9DE09C0_gshared (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_10 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mDC960E8E8D846BDC150427E7B570FA8F37E2884A_gshared (WhereSelectArrayIterator_2_tFC46B82974F3EC3860FA22FD22178C86245A64D7* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m16BFD018A35DE6CAC3F62621710A5BD2FC1C8A4C_gshared (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* __this, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_m53827DB1F65066EEDAFECA8B874AE7ABC0997E34_gshared (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_0 = __this->___source;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = __this->___predicate;
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* L_3 = (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m16BFD018A35DE6CAC3F62621710A5BD2FC1C8A4C(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m7C2141DC73DC2CF4C4DB03A723498D9FB60C4DD1_gshared (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_7 = __this->___predicate;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_10 = __this->___selector;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mA9178AF0B3E09F8E67F1C1C8CF987C14778A2155_gshared (WhereSelectArrayIterator_2_t9E4C41F46BF92865FCD1DC8A203E7173D21B1C55* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m67C715A12D5EA7E5ED4904A18B3A6486C0E25AE5_gshared (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* __this, SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m81468B8A82AC03065F49BABD489D066DE55E1250_gshared (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_0 = __this->___source;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = __this->___predicate;
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* L_3 = (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m67C715A12D5EA7E5ED4904A18B3A6486C0E25AE5(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m755E486658578A77AED86514B5AC65833D55A8E5_gshared (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_7 = __this->___predicate;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_10 = __this->___selector;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		SubstringU5BU5D_t9973080FDB519ED771E9FB3E6FDC90DF45211B77* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mA24BEE319B526F1944F2DA41D03449633CB975DE_gshared (WhereSelectArrayIterator_2_t3604DE3C318D94547F03D939CA5B46B13CDCD6CE* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mB36566E259A4A615754DE7005361780B06CC6240_gshared (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_m9DDD156A67EC4FB02C2EA5E2FB9B0E4E76A3AF3B_gshared (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* L_3 = (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mB36566E259A4A615754DE7005361780B06CC6240(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m257A8A5CA17A34373E042CB2EF908E3AA2EFE6F7_gshared (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Il2CppSharedGenericObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_10 = __this->___selector;
		Il2CppSharedGenericObject* L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m54A3D0BBD4C72619BA010E931F0FAD16D2E9865F_gshared (WhereSelectArrayIterator_2_tA45CBDECB5078F0FA1116ED63890F07CB25E48CD* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m129509AA57628EC2BAACE1BAD0FE298C284E14FA_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* L_3 = (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m2D19DEC399673E08D0C217881BF0416EEE5356E9_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Il2CppSharedGenericObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_10 = __this->___selector;
		Il2CppSharedGenericObject* L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mFB641A55162A05D1965399C37BE6A3C15EA3992F_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mB15DB27A8DC3B4E00BCA6E8F63F00F7E374F76A4_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_instance_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectArrayIterator_2_Clone_mFBF81AE0E2B6F7A7A79FC98398E7A6AC0FD330E9_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* L_3 = (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mEF7E8E7B117D6D1147C53CAE838836974171392C_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8));
	const uint32_t SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	const Il2CppFullySharedGenericAny L_8 = L_4;
	const Il2CppFullySharedGenericAny L_11 = L_4;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	memset(V_0, 0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1));
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		int32_t L_2 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck(L_1);
		int32_t L_3 = L_2;
		il2cpp_codegen_memcpy(L_4, (L_1)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		il2cpp_codegen_memcpy(V_0, L_4, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		int32_t L_5 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), ((int32_t)il2cpp_codegen_add(L_5, 1)));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_8, V_0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		NullCheck(L_7);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)), il2cpp_rgctx_method(method->klass->rgctx_data, 9), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_10 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		NullCheck(L_10);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)), il2cpp_rgctx_method(method->klass->rgctx_data, 10), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericAny*)L_12);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),2), L_12, SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mD81DB59B1D07BC8DDB099A652B22BA9C1538D7A3_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mA98660451992CB2678A013CAF4CFE71538EB94DD_gshared (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_m4E7A22938871A1313FCF74ED707525463ADF7994_gshared (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = __this->___source;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = __this->___predicate;
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* L_3 = (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mA98660451992CB2678A013CAF4CFE71538EB94DD(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m4BBFC96E98E86206FBD833DA5A1012554CD3C97D_gshared (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_7 = __this->___predicate;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_10 = __this->___selector;
		int32_t L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mE2B54126CDB6A7AF94C4D0967843C7BB268E22FE_gshared (WhereSelectArrayIterator_2_t30573E5B8AFCBA9E2E351B294EB58C51BC105F60* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m0D34CE1A5CC641C5B010E503A0EDABA731F37317_gshared (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m9EB3AB293A4F3DE86245553D1576AE27C3AE93A5_gshared (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = __this->___source;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = __this->___predicate;
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* L_3 = (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m0D34CE1A5CC641C5B010E503A0EDABA731F37317(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m82765A5346D0143B538CA4E93C264BEFCD212A15_gshared (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_7 = __this->___predicate;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_10 = __this->___selector;
		int32_t L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mA0921868611C1B38F8C7CF5A730AFCF007747871_gshared (WhereSelectArrayIterator_2_t35C6C5B7279F90A9D4ECEBB1B96A1BB3656AD379* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m5E9395DC536466521AEEEAF170431DF4B9176166_gshared (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* __this, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectArrayIterator_2_Clone_mC5A6B0583158E5ED21E45A1EEB949B8E8B258BE3_gshared (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_0 = __this->___source;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = __this->___predicate;
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* L_3 = (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m5E9395DC536466521AEEEAF170431DF4B9176166(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m466F7FFC29D1657A54662FEDD38AE94E64D75CC3_gshared (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_7 = __this->___predicate;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_10 = __this->___selector;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_11 = V_0;
		NullCheck(L_10);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12;
		L_12 = Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mA2C457566D55083A81F0B79BCAA3A0BCFE6AF4F4_gshared (WhereSelectArrayIterator_2_tDEB30313ED49F538FFC4E5260A2D58975F5516A9* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55649
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m88597229D15D44A261E426CB2681EABEAEF6F7EA_gshared (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* __this, JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55650
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_mE246C47ABE84136EDC514AA66A24083F378C9F0F_gshared (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_0 = __this->___source;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = __this->___predicate;
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* L_3 = (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m88597229D15D44A261E426CB2681EABEAEF6F7EA(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55651
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mD772C0F12F8BE61933F902B8EE1CE09415720F5F_gshared (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_7 = __this->___predicate;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_10 = __this->___selector;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_11 = V_0;
		NullCheck(L_10);
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		JsonValueU5BU5D_tCC9BDCF1DE43F923B72BEF6FE9AB4FBAEF445DB3* L_14 = __this->___source;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m8C3B18BD8743B2C57E4763B10BC0F6EA7E8427C6_gshared (WhereSelectArrayIterator_2_t0F47340A8C491706168205EC9042120ECC9B9AA6* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m06D1F87A96E06281D76DB47276AB2EDAA06B3CA0_gshared (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, RuntimeObject* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_m721DB777066CE243331CED451CEED89CBAFFFEBA_gshared (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = __this->___predicate;
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* L_3 = (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m06D1F87A96E06281D76DB47276AB2EDAA06B3CA0(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m7B8E6578AACE84F912CB10275E7288A5B2E89A69_gshared (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m6100ED488786A802CAFBC7E17525EF6A7BDC94B8_gshared (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_6;
		L_6 = InterfaceFuncInvoker0< KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_8 = __this->___predicate;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_11 = __this->___selector;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m9D3D869D9927B26DF1D42E73A79CC05EE8522C61_gshared (WhereSelectEnumerableIterator_2_t7C3246DCB4157B216CAE4F6BF15588FF4FCC46FB* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m3E31112974492F14302B2F2AD44556E3F190D600_gshared (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, RuntimeObject* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m05A70BB8B43D25FC51604D2A9E1A019B3A7577AE_gshared (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = __this->___predicate;
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* L_3 = (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m3E31112974492F14302B2F2AD44556E3F190D600(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m857A427E8CA5DD97803512641305C07FBFF4ABBE_gshared (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m68ECFBEB3E7FAF44C92FA477FFF75C976D044788_gshared (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_6;
		L_6 = InterfaceFuncInvoker0< KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_8 = __this->___predicate;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_11 = __this->___selector;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mE713C9782FC37C70D244A273617D240ADF4C7572_gshared (WhereSelectEnumerableIterator_2_t37BDA51AF5CAF438CB485B379F756900FC0EDB98* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m7C83BFD2FAE565BCEAA43B821FC018C4809E4329_gshared (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_mB8611201F27AECE73B83676F409DA1324C4AD743_gshared (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* L_3 = (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m7C83BFD2FAE565BCEAA43B821FC018C4809E4329(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m08B7B5790EF83624C9464666DD67D0E829613509_gshared (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mEA4834EA55DDC9ABA434A4313ECAB34DE725231D_gshared (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6;
		L_6 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_8 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_11 = __this->___selector;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mB6CA42D7626A1DB657D2E863ABB88D8279A9B849_gshared (WhereSelectEnumerableIterator_2_t63DF8B8C948F8F61F06FA7E4CA2C34360E76BEC1* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m864CB7770F7267D05BAD1722C5B1A733D0D2F11D_gshared (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, RuntimeObject* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m38948A0F156E094DAFFC0E70ABDD0EA728D62F18_gshared (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* L_3 = (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m864CB7770F7267D05BAD1722C5B1A733D0D2F11D(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_mFA1B2237222EC09B929EE004FEE1835664736072_gshared (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m6A672EC11C12AA683B852989745E323CF1683672_gshared (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6;
		L_6 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_8 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_11 = __this->___selector;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mE131809FAC4BFB44BFF375BA60B40DB757E49E9D_gshared (WhereSelectEnumerableIterator_2_t34F59AED41B6DFE677043B2A6D295FCCB9EFEF6C* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m23B52E787C9DD0F0644C7C1193C70E0FC4D5F716_gshared (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, RuntimeObject* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_m0ABACBD754386A1BBA4B1FE8FAD1531C5B4396B2_gshared (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = __this->___predicate;
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* L_3 = (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m23B52E787C9DD0F0644C7C1193C70E0FC4D5F716(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m275C9ECEA9EF9765A1E7AA1F15DEA5ABC47021D1_gshared (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mD87902A30A950D081B73A29E3EB9419924823468_gshared (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_6;
		L_6 = InterfaceFuncInvoker0< NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_8 = __this->___predicate;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_11 = __this->___selector;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m076D63890D2854FF95ED011E760CA8EF8A88EE6A_gshared (WhereSelectEnumerableIterator_2_t8E21B6F6EA8071DBFB34E7344CABD2FC17E41C15* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mA5886BEC6AD8C08CAA9D486ED97CECF94967ACE3_gshared (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, RuntimeObject* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m75BA459B1A73782489913A2F2F372366F532477E_gshared (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = __this->___predicate;
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* L_3 = (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_mA5886BEC6AD8C08CAA9D486ED97CECF94967ACE3(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m54B64CF6D96E1A70F500C4DD583FE5942186FBC0_gshared (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mBC6E1EE99FB52A3FD061E7ADA71E47829B8E82B4_gshared (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_6;
		L_6 = InterfaceFuncInvoker0< NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_8 = __this->___predicate;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_11 = __this->___selector;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m2C108D7BAF272D0759C47F8A9BEE0662BD445F03_gshared (WhereSelectEnumerableIterator_2_tA7FCB9D11FAFACF62D38A5BCB882727701264866* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m970919BF72719E9D8530FAEAAB5BE98DE0C88E86_gshared (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, RuntimeObject* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_mE839B184A60F53B589454D859335B3485019B9CB_gshared (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = __this->___predicate;
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* L_3 = (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m970919BF72719E9D8530FAEAAB5BE98DE0C88E86(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m7BAE97644DA5741246B97DA01A93C6A9F52A573A_gshared (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mEF3EF5D2BB3654950FDE31CA70E768B20F15451B_gshared (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_6;
		L_6 = InterfaceFuncInvoker0< NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_8 = __this->___predicate;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_11 = __this->___selector;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m8C0439E4E2E1DD5145BD5AA5C0DB3925DEBC4218_gshared (WhereSelectEnumerableIterator_2_t79A579557255664E30D6CFB0D42B03458D1B2AA1* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m11F43BDE67D2B239BB9318EF2B46930EB217CFB1_gshared (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, RuntimeObject* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m9089E635BCD07A62861D05D4991F7D8263405975_gshared (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = __this->___predicate;
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* L_3 = (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m11F43BDE67D2B239BB9318EF2B46930EB217CFB1(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m55859A6E71633681C477B350531100CB9EEB9B41_gshared (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m5208775412ACACE36AB428356B2EE4DF1A28C082_gshared (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_6;
		L_6 = InterfaceFuncInvoker0< NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_8 = __this->___predicate;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_11 = __this->___selector;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mF7BF4B6C7054BF1A001265E8406E1006300F5B88_gshared (WhereSelectEnumerableIterator_2_tC6EBFCF67051B22CA33E87109F034FA81BD66ADE* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m6A8FE8B4D2F17ADBC21012752F7F3BC952BAB662_gshared (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_mC574AA75393FDAC452077CDFAB68C6A09D19FD99_gshared (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* L_3 = (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m6A8FE8B4D2F17ADBC21012752F7F3BC952BAB662(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m4DF08E9579A8836F87609254EABECEC710549005_gshared (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mA3EE5B702CA0577CBEE9A7195D5E4F1A5CFC795A_gshared (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = InterfaceFuncInvoker0< StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m82956E842B6C3C446485B4955966043B035EC6BA_gshared (WhereSelectEnumerableIterator_2_tE6D9BD5B3ECF43FD4405FDD2C2254C4E31BDA366* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m2405C69F4B379D95DB5A0CD878DE173EF4EFC01B_gshared (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m58B2298AA013CDAAC8D4B31F583BD70B3488A67D_gshared (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* L_3 = (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m2405C69F4B379D95DB5A0CD878DE173EF4EFC01B(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m13A888DAF2892215F23E65D37A73A912B5975AE1_gshared (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m4889020D4D7790A7592BEAE08468A92C0B581EFA_gshared (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = InterfaceFuncInvoker0< StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m1D3DF3A3BD6C18C33E856E648DA220AC4C596B52_gshared (WhereSelectEnumerableIterator_2_t1D5E4F81F10AFCC1C7EFDA831FD664F7FDC9A0D7* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m25883F753A672BA40B723092E5FC096E5FD3E024_gshared (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, RuntimeObject* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_m428FAD38C0A13381EAFEEBBE727D56E0A8528E0E_gshared (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = __this->___predicate;
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* L_3 = (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m25883F753A672BA40B723092E5FC096E5FD3E024(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m5343CAFACBA2F66FA6478BAAEFD97C7CB9852688_gshared (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m708991A280E8CF2AACE9910D894ACFAC9BA1F5F2_gshared (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_6;
		L_6 = InterfaceFuncInvoker0< Substring_t2E16755269E6716C22074D6BC0A9099915E67849 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_8 = __this->___predicate;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_11 = __this->___selector;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m547CD0B55D6B7410C01A840EBEF37A370168DE32_gshared (WhereSelectEnumerableIterator_2_t7A8FD55B15A52D1CD2856CC42A68AFF27E8E4B52* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mEC4706B25165670D334B167CE048A3853D57B94D_gshared (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, RuntimeObject* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_mE5FA32032A2ED0D6949AC1F04011394982039D66_gshared (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = __this->___predicate;
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* L_3 = (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_mEC4706B25165670D334B167CE048A3853D57B94D(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m8D6DDE1AD465736E909A3F910FBD1B6D70F98887_gshared (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mA0F7C7DF00717802B878F6CB019A51497F71E300_gshared (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_6;
		L_6 = InterfaceFuncInvoker0< Substring_t2E16755269E6716C22074D6BC0A9099915E67849 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_8 = __this->___predicate;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_11 = __this->___selector;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m6F45C522350FC4957671E9277D0C406E0CDF6177_gshared (WhereSelectEnumerableIterator_2_t20B034C2DEBDBE13873B2FB72AE4D503D05F0D90* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mB87A71FACBF4EB861E6D35FCEEB809C46B5E3F1D_gshared (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_mAA7E96E9CDC4EFB3D5CC2057E5E7370EF44C9AB1_gshared (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* L_3 = (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_mB87A71FACBF4EB861E6D35FCEEB809C46B5E3F1D(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m7CACEE540401626C51D0F341CD785B3F67F772FC_gshared (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m0D1ED50FEB7CCDA77323A7824351B496F604E6C2_gshared (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		Il2CppSharedGenericObject* L_6;
		L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_8 = __this->___predicate;
		Il2CppSharedGenericObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_11 = __this->___selector;
		Il2CppSharedGenericObject* L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m818782FE1192B8528A950B411CB251FEB9AAB2CD_gshared (WhereSelectEnumerableIterator_2_t8CB56CB0F3BAFBA82F09F3248E5241A731015BA6* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m820E73DBEE027CB08633E586A635098AAD4B0243_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* L_3 = (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m811F2ABD9BC8A5CEEA64C0123A2887B865BF5823_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m1504811E695B69625751EA73048935D19FA8114E_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		Il2CppSharedGenericObject* L_6;
		L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_8 = __this->___predicate;
		Il2CppSharedGenericObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_11 = __this->___selector;
		Il2CppSharedGenericObject* L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mC9CB40941D1E86FB75CBB2F3A1101759C942F24F_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m9A4AF54DC527FA1CEF8B803C8DDA5E632838B06F_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_instance_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectEnumerableIterator_2_Clone_mD773B8B24D1459B11BA4462A6DD68865514ADC9E_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* L_3 = (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m640FAC111BC786414B40480BB03E4F84B2FFB179_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), (RuntimeObject*)NULL);
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mB384EFAF6366166F28EDFDBA272EEC1089E1A115_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12));
	const uint32_t SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 15));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	const Il2CppFullySharedGenericAny L_9 = L_6;
	const Il2CppFullySharedGenericAny L_12 = L_6;
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	memset(V_1, 0, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), L_4);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1), 2);
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck(L_5);
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5, (Il2CppFullySharedGenericAny*)L_6);
		il2cpp_codegen_memcpy(V_1, L_6, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_8 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_9, V_1, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		NullCheck(L_8);
		bool L_10;
		L_10 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_9: *(void**)L_9));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_11 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_memcpy(L_12, V_1, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		NullCheck(L_11);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 14)), il2cpp_rgctx_method(method->klass->rgctx_data, 14), L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_12: *(void**)L_12), (Il2CppFullySharedGenericAny*)L_13);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),2), L_13, SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mB8ACBBFA48460E67B18647EF16E6EE4D0BE08679_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 18)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m70325D0D69B22E471DBC07A8E4CA5D45E5853186_gshared (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, RuntimeObject* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_m7480BE9B41C13B15704A4285438D2E230A31B4B7_gshared (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = __this->___predicate;
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* L_3 = (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m70325D0D69B22E471DBC07A8E4CA5D45E5853186(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m7E38033ADB1C5EF0103C6900716FEEE2A0BE8BCC_gshared (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mE002FE8A8EC7D79FAB0978B40C0B8AA0F367CE28_gshared (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_8 = __this->___predicate;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_11 = __this->___selector;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m42D9DC397282C4705319B96A5646278AC656997A_gshared (WhereSelectEnumerableIterator_2_tE4973AFEF4C6F47F68C5845BC1600B7FCA7E58CD* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mA846116E73B9D1D46FEF744F0F0DEA950C8BA2C4_gshared (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, RuntimeObject* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_mFA5597D069F08318E2CED77FF132D242D473AA9F_gshared (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = __this->___predicate;
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* L_3 = (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_mA846116E73B9D1D46FEF744F0F0DEA950C8BA2C4(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_mBDC4F6B5AA2698914EA5009039E22D9E7F8B105C_gshared (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m9C218ABE79B327077F99E7F771F1854E3381BA48_gshared (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_8 = __this->___predicate;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_11 = __this->___selector;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mB443B47E9D28AAFAE71C3469A5F04F9C4824BA6E_gshared (WhereSelectEnumerableIterator_2_tBDA3AB3BAD5C31E1698E01C05B1DF56C8A3B2601* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m10782D149F90A9C4AB58038312DE7F0D44331AC3_gshared (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, RuntimeObject* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectEnumerableIterator_2_Clone_mCE5913364E39C357341D43DFFC88B2809164034F_gshared (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = __this->___predicate;
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* L_3 = (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m10782D149F90A9C4AB58038312DE7F0D44331AC3(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_mABAA1F8A41AE57923887AD927F0975CA30F0B68B_gshared (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		Iterator_1_Dispose_m202F0F3E8FFAA3098FE51C5F168900249540D23B((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mEF500E1C2D4A3406C2B7837F6CB0FCA978DADDA6_gshared (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_6;
		L_6 = InterfaceFuncInvoker0< JsonValue_t01DB320267C848E729A400EF2345979978F851D2 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_8 = __this->___predicate;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_11 = __this->___selector;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mABCE370031F4646530C3A52EDEE0CDAC946761D0_gshared (WhereSelectEnumerableIterator_2_tF244D1AD61638DBCE2856798487C6CDD5257681B* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55643
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m68319D9F7493E465D7A4220D85AC66B5F966B918_gshared (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, RuntimeObject* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55644
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m0F6490642A6BF150AA059D49954BD2F015FAD99B_gshared (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = __this->___predicate;
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* L_3 = (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m68319D9F7493E465D7A4220D85AC66B5F966B918(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55645
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m5F0B6C409B8D8AB6B14AEFE311FFC85AFCA01852_gshared (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
// Method Definition Index: 55646
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mAF596A3C5F2608649ABD9377030B09C3967B4194_gshared (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_6;
		L_6 = InterfaceFuncInvoker0< JsonValue_t01DB320267C848E729A400EF2345979978F851D2 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_8 = __this->___predicate;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_11 = __this->___selector;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55648
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mD6820658383D98D93E9FA5EC1D958B5C7AECD490_gshared (WhereSelectEnumerableIterator_2_tCB1BE1EC06FDD5216413619AF585D0F3407E4D51* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mFBB5A1617EF8B21105D01DEDB300F632817367CF_gshared (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* __this, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_mAB0D9054A572B843E11D353356BD722C493B4275_gshared (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* L_0 = __this->___source;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = __this->___predicate;
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_2 = __this->___selector;
		WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* L_3 = (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mFBB5A1617EF8B21105D01DEDB300F632817367CF(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mA8658C21CE561DE088B9A3F62A26B1AEB16E4305_gshared (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 L_4;
		L_4 = List_1_GetEnumerator_m1F0AB872867D4F4E39ADA790F9BAEEE7C4C041A4(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&((&(((&__this->___enumerator))->____current))->___value))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___value))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___value))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___value))->___anyValue), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* L_5 = (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01*)(&__this->___enumerator);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_6;
		L_6 = Enumerator_get_Current_mFED85C73E83B80F77C323CED265F927D8F56A4C2_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_8 = __this->___predicate;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* L_11 = __this->___selector;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* L_14 = (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m5C678E13B1EA842DC0035C25A5B4C317B298B675(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m787F0184ADD5FE059CE94DB8E4C3AAE2368E9DA6_gshared (WhereSelectListIterator_2_t2F8DD91F1BC955CAA54587DCC2736025CC957FF1* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m875604B216BC3B2A7CB3F2C7D5E835D7EB22427F_gshared (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* __this, List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* ___0_source, Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* ___1_predicate, Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mA295B6F5039F172A605128271C93F185399CC8ED_gshared (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* L_0 = __this->___source;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_1 = __this->___predicate;
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_2 = __this->___selector;
		WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* L_3 = (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m875604B216BC3B2A7CB3F2C7D5E835D7EB22427F(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mC786C806625F6E9FBAC59052BA90C2776846C3F9_gshared (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tBB0FDB6285D6D202D5728889B855427F1540E55B* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01 L_4;
		L_4 = List_1_GetEnumerator_m1F0AB872867D4F4E39ADA790F9BAEEE7C4C041A4(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&((&(((&__this->___enumerator))->____current))->___value))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___value))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___value))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___value))->___anyValue), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* L_5 = (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01*)(&__this->___enumerator);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_6;
		L_6 = Enumerator_get_Current_mFED85C73E83B80F77C323CED265F927D8F56A4C2_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* L_8 = __this->___predicate;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* L_11 = __this->___selector;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* L_14 = (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m5C678E13B1EA842DC0035C25A5B4C317B298B675(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m270A7E66739371F89A62657E2A7B2BAD81A6ACE2_gshared (WhereSelectListIterator_2_t1A636832E8492D88E3DE74D22A690243AC30FE52* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mF85D17BE66C1306EFCDD26409BE55B790F79EAC7_gshared (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* __this, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m937D5D1B7EC49BC4FAFEF932971777D72EED049F_gshared (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_2 = __this->___selector;
		WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* L_3 = (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mF85D17BE66C1306EFCDD26409BE55B790F79EAC7(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m08D934685D1F2120D36F9765312FE73F71D11A0C_gshared (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D L_4;
		L_4 = List_1_GetEnumerator_m29A75776B211A8A73BA0F0BDD4EE3F8AFB4F57D5(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_StringLowerCase), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* L_5 = (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D*)(&__this->___enumerator);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6;
		L_6 = Enumerator_get_Current_m6E5830352E5082086B6B8F79AB4DABC2A18414A3_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_8 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* L_11 = __this->___selector;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* L_14 = (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_mFF6CD854E66A32544CE8D1C58A74C324CE2E822E(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mBD04923D351FA549D359E8DE870BC9B749151AD5_gshared (WhereSelectListIterator_2_t689CF6744B5DA4348991EEB1526B6218E6AA7B76* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m5D37B1A65702955D7E80CA7E5D969190926DBF55_gshared (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* __this, List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* ___0_source, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___1_predicate, Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mA40C9F6A707A3B86FA4AEE948BCE4BEE7D3125AF_gshared (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* L_0 = __this->___source;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_1 = __this->___predicate;
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_2 = __this->___selector;
		WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* L_3 = (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m5D37B1A65702955D7E80CA7E5D969190926DBF55(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m19D9F393C36AE547D652D22A2B9BF480FC59BAC7_gshared (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t5F075F07C02D0CCF50D7FB6C844DE693B2851FC6* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D L_4;
		L_4 = List_1_GetEnumerator_m29A75776B211A8A73BA0F0BDD4EE3F8AFB4F57D5(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_StringOriginalCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_StringLowerCase), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* L_5 = (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D*)(&__this->___enumerator);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6;
		L_6 = Enumerator_get_Current_m6E5830352E5082086B6B8F79AB4DABC2A18414A3_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_8 = __this->___predicate;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* L_11 = __this->___selector;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* L_14 = (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_mFF6CD854E66A32544CE8D1C58A74C324CE2E822E(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m2B900E5ECBA7896C989DB547837C81A90DB56B21_gshared (WhereSelectListIterator_2_t91AA3474D9F92BA1EDDF3BA13AF37F8871A2928D* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mD72ECEB2A0980E5F93455365BA960143A34085DB_gshared (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* __this, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m796C8279CEB66ADDC80A7EAC36AEE08605979787_gshared (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* L_0 = __this->___source;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = __this->___predicate;
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_2 = __this->___selector;
		WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* L_3 = (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mD72ECEB2A0980E5F93455365BA960143A34085DB(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mAFCE990F26EBDDF656AA01807375D36544C63124_gshared (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 L_4;
		L_4 = List_1_GetEnumerator_mE145D413FF6CDAE7061E3B5CED7823B0EFCBB7F5(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CnameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* L_5 = (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054*)(&__this->___enumerator);
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_6;
		L_6 = Enumerator_get_Current_mE64095D45062ABD3FE097C12C8A767F4378A3658_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_8 = __this->___predicate;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* L_11 = __this->___selector;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* L_14 = (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m43A6E06C5BF5734DB6AD0687EF52131A51F0FCC8(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m1B9A768C2B1A26E615BCDB10078F5231CF0C4ADC_gshared (WhereSelectListIterator_2_t8CBDEA25D66F7ED9AE619E7B42005F154E1FAE81* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m10ACDEF2EB1838C9CC59D697642D3A2C761E5772_gshared (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* __this, List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* ___0_source, Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* ___1_predicate, Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mCDAEDADE3DACBEBF018471239A7E3E5517F78F3D_gshared (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* L_0 = __this->___source;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_1 = __this->___predicate;
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_2 = __this->___selector;
		WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* L_3 = (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m10ACDEF2EB1838C9CC59D697642D3A2C761E5772(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m7DCC1B1DD38D74782B3F5F542F8DE35EB39012C0_gshared (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tF542FB9F97D34CC06B085D6872645B0DC0AA5E43* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054 L_4;
		L_4 = List_1_GetEnumerator_mE145D413FF6CDAE7061E3B5CED7823B0EFCBB7F5(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CnameU3Ek__BackingField), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&(((&__this->___enumerator))->____current))->___U3CparametersU3Ek__BackingField))->___m_Array), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* L_5 = (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054*)(&__this->___enumerator);
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_6;
		L_6 = Enumerator_get_Current_mE64095D45062ABD3FE097C12C8A767F4378A3658_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* L_8 = __this->___predicate;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* L_11 = __this->___selector;
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* L_14 = (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m43A6E06C5BF5734DB6AD0687EF52131A51F0FCC8(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m661468D778ACC565D4BA1D91825F54845E23119D_gshared (WhereSelectListIterator_2_t7ECB676FA2E8B5B2F1EC59C5618083B83A56FCD4* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mACC4D7CA5223D22CBC36F756CA54BA80C06723C9_gshared (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* __this, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m89C4946CF9C7CA28F2091618685B85AA11EA3E87_gshared (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* L_0 = __this->___source;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = __this->___predicate;
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_2 = __this->___selector;
		WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* L_3 = (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mACC4D7CA5223D22CBC36F756CA54BA80C06723C9(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m7DCCE086E23C0D68D4F9AEF5E70291B76432AAF1_gshared (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 L_4;
		L_4 = List_1_GetEnumerator_m8E8CDE0EBC3A66F0257FD41A31A4055983A0665B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CnameU3Ek__BackingField), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* L_5 = (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06*)(&__this->___enumerator);
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_6;
		L_6 = Enumerator_get_Current_m83264A170B9E2284E4A91DD95D9E58A4AC7A065D_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_8 = __this->___predicate;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* L_11 = __this->___selector;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* L_14 = (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m8FDA47B1AB6128A33F2C41EAA3448D67A00A51C5(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mC6AFE32AA08E2CBC27F4433BA2319CA59306DC87_gshared (WhereSelectListIterator_2_tC7B82E7505D8326313C1B549FBFC1B0FFCCB513C* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mA2BC01EC05747FCB2048C22517C86446C3F307AB_gshared (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* __this, List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* ___0_source, Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* ___1_predicate, Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mFB0B3562093A0145E53DB670B39564E077E5627E_gshared (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* L_0 = __this->___source;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_1 = __this->___predicate;
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_2 = __this->___selector;
		WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* L_3 = (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mA2BC01EC05747FCB2048C22517C86446C3F307AB(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m44CB40F4FD58ABE961BCA7977CDDB1A8A86A2C0A_gshared (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t8A57A4B80A041F8DB4118B5BC7717E3FE6654C06* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06 L_4;
		L_4 = List_1_GetEnumerator_m8E8CDE0EBC3A66F0257FD41A31A4055983A0665B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___U3CnameU3Ek__BackingField), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* L_5 = (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06*)(&__this->___enumerator);
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_6;
		L_6 = Enumerator_get_Current_m83264A170B9E2284E4A91DD95D9E58A4AC7A065D_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* L_8 = __this->___predicate;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* L_11 = __this->___selector;
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* L_14 = (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m8FDA47B1AB6128A33F2C41EAA3448D67A00A51C5(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m38C6439F26B0E25617D3F34239157491AC02E7F5_gshared (WhereSelectListIterator_2_t87AE4912FB509138ED53A11BFCE31DB3FC4AA197* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m9435C8BAA035BE07F3983A2F3C06D5F3F2EF97BF_gshared (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m203266656A861AB9FCE85C6265CBB81759D6EC78_gshared (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_2 = __this->___selector;
		WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* L_3 = (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m9435C8BAA035BE07F3983A2F3C06D5F3F2EF97BF(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m441444FFC4A56B13F1DCFA2E6C732972CC286B71_gshared (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F L_4;
		L_4 = List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_Value), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___tempData), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_5 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_14 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m2B9342EC90171F99141E32C1E7D1126C61888256_gshared (WhereSelectListIterator_2_tFF1361706039E12FA707C48FE62FD0A43731B6EA* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m4E5213AEA3F49172211F4EFA18DF14269D3DCEFE_gshared (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_m3D551BAA9B503C37E69101F9E6762C6CDEAE28A9_gshared (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_2 = __this->___selector;
		WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* L_3 = (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m4E5213AEA3F49172211F4EFA18DF14269D3DCEFE(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m76BCFD689F5A1DEFB96F737A185862A2A8DAEBEC_gshared (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F L_4;
		L_4 = List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_Value), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___tempData), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_5 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_14 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m5690D7E5591C6EACE4C1565766169D29108A381B_gshared (WhereSelectListIterator_2_t875258CFE39A44D5FA3789786E8AED4CE77BC5A1* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m76DFD3D8B5B62444383A84BE159C61CBE99D98DA_gshared (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* __this, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m7514B4D4CA43073C8D6D3B10D6B33C562464A0C8_gshared (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* L_0 = __this->___source;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = __this->___predicate;
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_2 = __this->___selector;
		WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* L_3 = (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m76DFD3D8B5B62444383A84BE159C61CBE99D98DA(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m9801C3269DA1FCC381EED100CE2C710B10873FDE_gshared (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 L_4;
		L_4 = List_1_GetEnumerator_m2E8AAA332A1CCE110C46806675D27756C848C264(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_String), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* L_5 = (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785*)(&__this->___enumerator);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_6;
		L_6 = Enumerator_get_Current_m543479141C23CB5A761FFAE440388CA38F12F73A_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_8 = __this->___predicate;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* L_11 = __this->___selector;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* L_14 = (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_mBD8837024473F97D1F793AD3DF5E27568D7BDD06(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m54A65CB2977BDF55DA3004F81CF889F22E233DE9_gshared (WhereSelectListIterator_2_t783076280AA5A0279F1CF30B5F192A923D62C1E7* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6A90F8B7CC3A2042DF6441296DB1FFC2D5862FF6_gshared (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* __this, List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* ___0_source, Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* ___1_predicate, Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_m1FD1A4D3AB210643F6B5488904F2246D0BC5936F_gshared (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* L_0 = __this->___source;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_1 = __this->___predicate;
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_2 = __this->___selector;
		WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* L_3 = (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m6A90F8B7CC3A2042DF6441296DB1FFC2D5862FF6(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m277C36D14D74DFD954C3FF2A7A8EEC853C2CE2CF_gshared (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tC4C8D746916C433D3343B92925052F1B9DB34A29* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785 L_4;
		L_4 = List_1_GetEnumerator_m2E8AAA332A1CCE110C46806675D27756C848C264(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_String), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* L_5 = (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785*)(&__this->___enumerator);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_6;
		L_6 = Enumerator_get_Current_m543479141C23CB5A761FFAE440388CA38F12F73A_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* L_8 = __this->___predicate;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* L_11 = __this->___selector;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* L_14 = (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_mBD8837024473F97D1F793AD3DF5E27568D7BDD06(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mDE6600D4AC057ADFB85F5E575E0DD86A4D075AE8_gshared (WhereSelectListIterator_2_t49639E537BBE3F0D6A7A2342E3B55342C8BB8EC3* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mF00B95B59197D6CEA2311875016BA798A7180FD4_gshared (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m4A58D07E54347E0DAABEA92F211B8A1F230C6394_gshared (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_2 = __this->___selector;
		WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* L_3 = (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mF00B95B59197D6CEA2311875016BA798A7180FD4(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m1A73A98D8BE9B66C6E1EA898FE0076B45DE64D7F_gshared (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_4;
		L_4 = List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_5 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		Il2CppSharedGenericObject* L_6;
		L_6 = Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_8 = __this->___predicate;
		Il2CppSharedGenericObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* L_11 = __this->___selector;
		Il2CppSharedGenericObject* L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_14 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m131B86D1CE4E5F37D5EE98A1E477C5D8A812F73F_gshared (WhereSelectListIterator_2_t773350559501AE1914B16E32884C44B0D31DEB1A* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mA526287F988AD67F1AFD8DDA6ED50D6223EB1F01_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = __this->___selector;
		WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* L_3 = (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m330FDD6ED7F4BEE49DCBC8A651E09A6A353C395E_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_4;
		L_4 = List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_5 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		Il2CppSharedGenericObject* L_6;
		L_6 = Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_8 = __this->___predicate;
		Il2CppSharedGenericObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_11 = __this->___selector;
		Il2CppSharedGenericObject* L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_14 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m188F9A25121C29C31230434548BA57C395C1C9DE_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6BFCBB5460270ED1896D24DC7E3B83F4950D2140_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_instance_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectListIterator_2_Clone_m8EC8E684FFDC3BC579DF37C08993B7F80966639D_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* L_3 = (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		((  void (*) (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mBB81EEF5DFFEBDDB1AC24116FAD1D13505525569_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12));
	const uint32_t SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 9));
	const uint32_t SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 15));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	const Il2CppFullySharedGenericAny L_8 = L_5;
	const Il2CppFullySharedGenericAny L_11 = L_5;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05);
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_4 = alloca(SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	memset(V_1, 0, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_3 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		InvokerActionInvoker1< Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 8)), il2cpp_rgctx_method(method->klass->rgctx_data, 8), L_3, (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_4);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), L_4, SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1), 2);
		goto IL_0061;
	}

IL_002b:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)), il2cpp_rgctx_method(method->klass->rgctx_data, 10), (((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3)))), (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_1, L_5, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		if (!L_6)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_8, V_1, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		NullCheck(L_7);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_10 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_memcpy(L_11, V_1, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		NullCheck(L_10);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 14)), il2cpp_rgctx_method(method->klass->rgctx_data, 14), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericAny*)L_12);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),2), L_12, SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05);
		return (bool)1;
	}

IL_0061:
	{
		bool L_13;
		L_13 = ((  bool (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 16)))((((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3)))), il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_13)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m1739BDD134D3AF5A55DBB06AEE130B0C58E47014_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 20)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mAC9D7E0CCA4B15AEFA7AF154091F7E82E23A1C25_gshared (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m667BB30E035CF2CF5C7CC090A93EF5999E3A507B_gshared (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_0 = __this->___source;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = __this->___predicate;
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_2 = __this->___selector;
		WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* L_3 = (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mAC9D7E0CCA4B15AEFA7AF154091F7E82E23A1C25(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mC00400D119EFD5217DADEAC7FC870165DDD3619D_gshared (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_4;
		L_4 = List_1_GetEnumerator_mEF61540761E14807B2930879741EF5E1E973FCE8(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* L_5 = (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*)(&__this->___enumerator);
		int32_t L_6;
		L_6 = Enumerator_get_Current_m27A9B9D3732FA85AE5063328B42817D18F991988_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_8 = __this->___predicate;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* L_11 = __this->___selector;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* L_14 = (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m6054C979BCD753583C00269861523701392B935A(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mFC0CE1F7C7A9CFE1C1A7A57BF9FC04E3F59B12FD_gshared (WhereSelectListIterator_2_t1B9E25819166909009FA31DF2F03117C8D0F783F* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mDD1F6B9427F21DDC9B7304C6445F4CE23F01B2F5_gshared (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_source, Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* ___1_predicate, Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_m2E7761856CBD3CB0B74488A8297A4D03C6C5224C_gshared (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_0 = __this->___source;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_1 = __this->___predicate;
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_2 = __this->___selector;
		WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* L_3 = (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mDD1F6B9427F21DDC9B7304C6445F4CE23F01B2F5(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m87B4188E471597108BBA231B780E29AB9D962A9B_gshared (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_4;
		L_4 = List_1_GetEnumerator_mEF61540761E14807B2930879741EF5E1E973FCE8(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* L_5 = (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*)(&__this->___enumerator);
		int32_t L_6;
		L_6 = Enumerator_get_Current_m27A9B9D3732FA85AE5063328B42817D18F991988_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* L_8 = __this->___predicate;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* L_11 = __this->___selector;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* L_14 = (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m6054C979BCD753583C00269861523701392B935A(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m09AB57C26990601C313EB1AD262947B08F85A06E_gshared (WhereSelectListIterator_2_t48B7058AB66C2C52050B162742ACAF16C6011285* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mA16961886A67BC49FFE65D6057D3BA28D407DF89_gshared (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* __this, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m1B09BFBB8B83E605D7C7487F0E6A4986CE070943((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D* WhereSelectListIterator_2_Clone_m01258FBF3047EACEBBBE89855BDAE5197B095A79_gshared (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* L_0 = __this->___source;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = __this->___predicate;
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_2 = __this->___selector;
		WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* L_3 = (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_mA16961886A67BC49FFE65D6057D3BA28D407DF89(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mE119EF6FA88D7E63491FC5611A5F34D3602F5D1B_gshared (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB L_4;
		L_4 = List_1_GetEnumerator_mE2A3E04FB3B522B90EBAC4EFFF9614F47FE19D13(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&(((&__this->___enumerator))->____current))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___anyValue), (void*)NULL);
		#endif
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* L_5 = (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB*)(&__this->___enumerator);
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_6;
		L_6 = Enumerator_get_Current_m9F9305DFA7957A66E104431A3EB3D5C071B4587D_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_8 = __this->___predicate;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* L_11 = __this->___selector;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_12 = V_1;
		NullCheck(L_11);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_13;
		L_13 = Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this)->___current))->___m_StringLowerCase), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* L_14 = (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m698365CC16BD65E80A0737FD26ED23F19C8AE5DF(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tE6B605B8CEAAA7680455D82B5BF52914D0C3892D*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mAEEE2C3DA2DBA62F84C02FE5EDD8894338DC5D55_gshared (WhereSelectListIterator_2_t6C3621A89FA834F0251E7EF9F3484147BB4FD39E* __this, Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C* L_1 = (WhereEnumerableIterator_1_t98114935A3AA4F0199B53A5027B776D5AFF9AF6C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m0C64291A42967A645028F01B6069873BFB0831E4(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 55654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m366B0E85B127808BA5964E491DFF0091C853529C_gshared (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* __this, List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___0_source, Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* ___1_predicate, Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* ___2_selector, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
// Method Definition Index: 55655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mD5CAE504F9C99D269DDBE8024BBB3A720B57903E_gshared (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* L_0 = __this->___source;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_1 = __this->___predicate;
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_2 = __this->___selector;
		WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* L_3 = (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m366B0E85B127808BA5964E491DFF0091C853529C(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
// Method Definition Index: 55656
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mE11050266689AB3FED99AFC03D14D35FB57B0835_gshared (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB L_4;
		L_4 = List_1_GetEnumerator_mE2A3E04FB3B522B90EBAC4EFFF9614F47FE19D13(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&(((&__this->___enumerator))->____current))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___anyValue), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* L_5 = (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB*)(&__this->___enumerator);
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_6;
		L_6 = Enumerator_get_Current_m9F9305DFA7957A66E104431A3EB3D5C071B4587D_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* L_8 = __this->___predicate;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* L_11 = __this->___selector;
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_12 = V_1;
		NullCheck(L_11);
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* L_14 = (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m698365CC16BD65E80A0737FD26ED23F19C8AE5DF(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
// Method Definition Index: 55658
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m18B457233CE2D525123CCAE02C5ACF2CDC0ABD46_gshared (WhereSelectListIterator_2_t8D92221CC05EE04607C9E639B24E550475B4B32C* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 37457
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_m8B26C5F2B3AB3C05CB4ACDE5A17C6559BDEF503C_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = ___0_src;
		int32_t L_1 = ___1_srcLen;
		WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF(__this, L_0, 0, L_1, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1));
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1__ctor_m8B26C5F2B3AB3C05CB4ACDE5A17C6559BDEF503C_AdjustorThunk (RuntimeObject* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	WorkSlice_1__ctor_m8B26C5F2B3AB3C05CB4ACDE5A17C6559BDEF503C(_thisAdjusted, ___0_src, ___1_srcLen, method);
}
// Method Definition Index: 37458
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* G_B2_0 = NULL;
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* G_B3_1 = NULL;
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = ___0_src;
		__this->___m_Data = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Data), (void*)L_0);
		int32_t L_1 = ___1_srcStart;
		__this->___m_Start = L_1;
		int32_t L_2 = ___2_srcLen;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			G_B2_0 = __this;
			goto IL_001e;
		}
		G_B1_0 = __this;
	}
	{
		int32_t L_3 = ___2_srcLen;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_4 = ___0_src;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		int32_t L_6;
		L_6 = Math_Min_m53C488772A34D53917BCA2A491E79A0A5356ED52(L_3, L_5, NULL);
		G_B3_0 = L_6;
		G_B3_1 = G_B1_0;
		goto IL_0021;
	}

IL_001e:
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = ___0_src;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		G_B3_0 = L_8;
		G_B3_1 = G_B2_0;
	}

IL_0021:
	{
		G_B3_1->___m_Length = G_B3_0;
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF_AdjustorThunk (RuntimeObject* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	WorkSlice_1__ctor_mF7CEAE61925236C3A0BE9E92E9B97B65EF5DFFEF(_thisAdjusted, ___0_src, ___1_srcStart, ___2_srcLen, method);
}
// Method Definition Index: 37459
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 WorkSlice_1_get_Item_m31D876CE45C89B17D24E2D2EB6534C4150D72EE5_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = __this->___m_Data;
		int32_t L_1 = __this->___m_Start;
		int32_t L_2 = ___0_index;
		NullCheck(L_0);
		int32_t L_3 = ((int32_t)il2cpp_codegen_add(L_1, L_2));
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_4 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
IL2CPP_EXTERN_C  Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 WorkSlice_1_get_Item_m31D876CE45C89B17D24E2D2EB6534C4150D72EE5_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 _returnValue;
	_returnValue = WorkSlice_1_get_Item_m31D876CE45C89B17D24E2D2EB6534C4150D72EE5(_thisAdjusted, ___0_index, method);
	return _returnValue;
}
// Method Definition Index: 37460
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_set_Item_m242025FA56F79603361582298B70AB2284A12067_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = __this->___m_Data;
		int32_t L_1 = __this->___m_Start;
		int32_t L_2 = ___0_index;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_3 = ___1_value;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_1, L_2))), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_3);
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_set_Item_m242025FA56F79603361582298B70AB2284A12067_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	WorkSlice_1_set_Item_m242025FA56F79603361582298B70AB2284A12067(_thisAdjusted, ___0_index, ___1_value, method);
}
// Method Definition Index: 37461
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	int32_t _returnValue;
	_returnValue = WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 37462
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_capacity_m514E3E1482974088A807521F9E2C481EB83C25F8_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = __this->___m_Data;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		return L_1;
	}
}
IL2CPP_EXTERN_C  int32_t WorkSlice_1_get_capacity_m514E3E1482974088A807521F9E2C481EB83C25F8_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	int32_t _returnValue;
	_returnValue = WorkSlice_1_get_capacity_m514E3E1482974088A807521F9E2C481EB83C25F8(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 37463
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_Sort_m9DF994BABD5BF00DE8FEB14D82F7A0A9F6CAEE3D_gshared (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* ___0_compare, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		if ((((int32_t)L_0) <= ((int32_t)1)))
		{
			goto IL_002a;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_1 = __this->___m_Data;
		int32_t L_2 = __this->___m_Start;
		int32_t L_3 = __this->___m_Start;
		int32_t L_4 = __this->___m_Length;
		Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* L_5 = ___0_compare;
		il2cpp_codegen_runtime_class_init_inline(Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var);
		Sorting_QuickSort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mB8556CFA6B9237741AAA1ADF2EE68AA3696F9477(L_1, L_2, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_3, L_4)), 1)), L_5, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_Sort_m9DF994BABD5BF00DE8FEB14D82F7A0A9F6CAEE3D_AdjustorThunk (RuntimeObject* __this, Func_3_tD46831209E6E19204CD8F9EAFC74DBFCA3C36C5F* ___0_compare, const RuntimeMethod* method)
{
	WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44>(__this);
	WorkSlice_1_Sort_m9DF994BABD5BF00DE8FEB14D82F7A0A9F6CAEE3D(_thisAdjusted, ___0_compare, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 37457
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_mFEB81358558CEF0264CCE077535DB880EA2492BA_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_src;
		int32_t L_1 = ___1_srcLen;
		((  void (*) (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1)))(__this, L_0, 0, L_1, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1));
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1__ctor_mFEB81358558CEF0264CCE077535DB880EA2492BA_AdjustorThunk (RuntimeObject* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	WorkSlice_1__ctor_mFEB81358558CEF0264CCE077535DB880EA2492BA(_thisAdjusted, ___0_src, ___1_srcLen, method);
}
// Method Definition Index: 37458
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_m7AC3CC7AABC83B76D23D2B94329DD4D0200156FA_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* G_B2_0 = NULL;
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* G_B3_1 = NULL;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_src;
		__this->___m_Data = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Data), (void*)L_0);
		int32_t L_1 = ___1_srcStart;
		__this->___m_Start = L_1;
		int32_t L_2 = ___2_srcLen;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			G_B2_0 = __this;
			goto IL_001e;
		}
		G_B1_0 = __this;
	}
	{
		int32_t L_3 = ___2_srcLen;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = ___0_src;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		int32_t L_6;
		L_6 = Math_Min_m53C488772A34D53917BCA2A491E79A0A5356ED52(L_3, L_5, NULL);
		G_B3_0 = L_6;
		G_B3_1 = G_B1_0;
		goto IL_0021;
	}

IL_001e:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = ___0_src;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		G_B3_0 = L_8;
		G_B3_1 = G_B2_0;
	}

IL_0021:
	{
		G_B3_1->___m_Length = G_B3_0;
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1__ctor_m7AC3CC7AABC83B76D23D2B94329DD4D0200156FA_AdjustorThunk (RuntimeObject* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	WorkSlice_1__ctor_m7AC3CC7AABC83B76D23D2B94329DD4D0200156FA(_thisAdjusted, ___0_src, ___1_srcStart, ___2_srcLen, method);
}
// Method Definition Index: 37459
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_get_Item_mFDEC427E08156ECD6879AD45AEE3618B43E3F726_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 4));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A);
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->___m_Data;
		int32_t L_1 = __this->___m_Start;
		int32_t L_2 = ___0_index;
		NullCheck(L_0);
		int32_t L_3 = ((int32_t)il2cpp_codegen_add(L_1, L_2));
		il2cpp_codegen_memcpy(L_4, (L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A);
		il2cpp_codegen_memcpy(il2cppRetVal, L_4, SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A);
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_get_Item_mFDEC427E08156ECD6879AD45AEE3618B43E3F726_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	WorkSlice_1_get_Item_mFDEC427E08156ECD6879AD45AEE3618B43E3F726(_thisAdjusted, ___0_index, il2cppRetVal, method);
	return;
}
// Method Definition Index: 37460
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_set_Item_m757F8BE76FAE27C149DE7C474A2B1845E08A5A0F_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 4));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A);
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->___m_Data;
		int32_t L_1 = __this->___m_Start;
		int32_t L_2 = ___0_index;
		il2cpp_codegen_memcpy(L_3, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 4)) ? ___1_value : &___1_value), SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A);
		NullCheck(L_0);
		il2cpp_codegen_memcpy((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_1, L_2)))), L_3, SizeOf_T_tA71336896536EBCB168400E4D351FEE422324E7A);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 4), (void**)(L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_1, L_2)))), (void*)L_3);
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_set_Item_m757F8BE76FAE27C149DE7C474A2B1845E08A5A0F_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	WorkSlice_1_set_Item_m757F8BE76FAE27C149DE7C474A2B1845E08A5A0F(_thisAdjusted, ___0_index, ___1_value, method);
}
// Method Definition Index: 37461
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	int32_t _returnValue;
	_returnValue = WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 37462
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_capacity_mCF0D603B7EC6E6037D0E1A14D8D0F49AD063E59E_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->___m_Data;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		return L_1;
	}
}
IL2CPP_EXTERN_C  int32_t WorkSlice_1_get_capacity_mCF0D603B7EC6E6037D0E1A14D8D0F49AD063E59E_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	int32_t _returnValue;
	_returnValue = WorkSlice_1_get_capacity_mCF0D603B7EC6E6037D0E1A14D8D0F49AD063E59E(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 37463
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_Sort_mE2ED392BDF8F4F4141D7BF4C984EFE943F607A94_gshared (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9* ___0_compare, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		if ((((int32_t)L_0) <= ((int32_t)1)))
		{
			goto IL_002a;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = __this->___m_Data;
		int32_t L_2 = __this->___m_Start;
		int32_t L_3 = __this->___m_Start;
		int32_t L_4 = __this->___m_Length;
		Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9* L_5 = ___0_compare;
		il2cpp_codegen_runtime_class_init_inline(Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var);
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6)))(L_1, L_2, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_3, L_4)), 1)), L_5, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_Sort_mE2ED392BDF8F4F4141D7BF4C984EFE943F607A94_AdjustorThunk (RuntimeObject* __this, Func_3_tECED1961B53AB164A131061296ABA1276B4FBBB9* ___0_compare, const RuntimeMethod* method)
{
	WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809>(__this);
	WorkSlice_1_Sort_mE2ED392BDF8F4F4141D7BF4C984EFE943F607A94(_thisAdjusted, ___0_compare, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 37457
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_m76CCC65E3DFB8B84A2154B65A79B56688F9B26A4_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_0 = ___0_src;
		int32_t L_1 = ___1_srcLen;
		WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0(__this, L_0, 0, L_1, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1));
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1__ctor_m76CCC65E3DFB8B84A2154B65A79B56688F9B26A4_AdjustorThunk (RuntimeObject* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcLen, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	WorkSlice_1__ctor_m76CCC65E3DFB8B84A2154B65A79B56688F9B26A4(_thisAdjusted, ___0_src, ___1_srcLen, method);
}
// Method Definition Index: 37458
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* G_B2_0 = NULL;
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* G_B3_1 = NULL;
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_0 = ___0_src;
		__this->___m_Data = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Data), (void*)L_0);
		int32_t L_1 = ___1_srcStart;
		__this->___m_Start = L_1;
		int32_t L_2 = ___2_srcLen;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			G_B2_0 = __this;
			goto IL_001e;
		}
		G_B1_0 = __this;
	}
	{
		int32_t L_3 = ___2_srcLen;
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_4 = ___0_src;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		int32_t L_6;
		L_6 = Math_Min_m53C488772A34D53917BCA2A491E79A0A5356ED52(L_3, L_5, NULL);
		G_B3_0 = L_6;
		G_B3_1 = G_B1_0;
		goto IL_0021;
	}

IL_001e:
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_7 = ___0_src;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		G_B3_0 = L_8;
		G_B3_1 = G_B2_0;
	}

IL_0021:
	{
		G_B3_1->___m_Length = G_B3_0;
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0_AdjustorThunk (RuntimeObject* __this, LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* ___0_src, int32_t ___1_srcStart, int32_t ___2_srcLen, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	WorkSlice_1__ctor_mC3BCAA8301A4E37DDB26811AAFFE1A3654FA47D0(_thisAdjusted, ___0_src, ___1_srcStart, ___2_srcLen, method);
}
// Method Definition Index: 37459
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 WorkSlice_1_get_Item_mFD8EE50B88077F3EF9BCEF97BD6D0352D2E8445D_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_0 = __this->___m_Data;
		int32_t L_1 = __this->___m_Start;
		int32_t L_2 = ___0_index;
		NullCheck(L_0);
		int32_t L_3 = ((int32_t)il2cpp_codegen_add(L_1, L_2));
		LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 L_4 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
IL2CPP_EXTERN_C  LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 WorkSlice_1_get_Item_mFD8EE50B88077F3EF9BCEF97BD6D0352D2E8445D_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 _returnValue;
	_returnValue = WorkSlice_1_get_Item_mFD8EE50B88077F3EF9BCEF97BD6D0352D2E8445D(_thisAdjusted, ___0_index, method);
	return _returnValue;
}
// Method Definition Index: 37460
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_set_Item_m070889CA2F62E82384BAB3CEF6D6E9AABF153663_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, int32_t ___0_index, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_0 = __this->___m_Data;
		int32_t L_1 = __this->___m_Start;
		int32_t L_2 = ___0_index;
		LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 L_3 = ___1_value;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_1, L_2))), (LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2)L_3);
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_set_Item_m070889CA2F62E82384BAB3CEF6D6E9AABF153663_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, LightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2 ___1_value, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	WorkSlice_1_set_Item_m070889CA2F62E82384BAB3CEF6D6E9AABF153663(_thisAdjusted, ___0_index, ___1_value, method);
}
// Method Definition Index: 37461
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	int32_t _returnValue;
	_returnValue = WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 37462
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_capacity_m98A237D126494A11FF3C61211B36A790E4E8A3B0_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_0 = __this->___m_Data;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		return L_1;
	}
}
IL2CPP_EXTERN_C  int32_t WorkSlice_1_get_capacity_m98A237D126494A11FF3C61211B36A790E4E8A3B0_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	int32_t _returnValue;
	_returnValue = WorkSlice_1_get_capacity_m98A237D126494A11FF3C61211B36A790E4E8A3B0(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 37463
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WorkSlice_1_Sort_m7EF532E936D55845DAAC606C0A214FE48EBF8584_gshared (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___0_compare, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		if ((((int32_t)L_0) <= ((int32_t)1)))
		{
			goto IL_002a;
		}
	}
	{
		LightCookieMappingU5BU5D_tE1F10A7D54920D3636F1DB7774B3D5F5B560E263* L_1 = __this->___m_Data;
		int32_t L_2 = __this->___m_Start;
		int32_t L_3 = __this->___m_Start;
		int32_t L_4 = __this->___m_Length;
		Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* L_5 = ___0_compare;
		il2cpp_codegen_runtime_class_init_inline(Sorting_tBB4ACAADCAA21EA710DD3998A0614ABDEF8FD8A6_il2cpp_TypeInfo_var);
		Sorting_QuickSort_TisLightCookieMapping_t76B317D9FDE96056FA698B46B45D7F0937BD02D2_mD7019ED48D20810C1169430283118F96945E9450(L_1, L_2, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_3, L_4)), 1)), L_5, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void WorkSlice_1_Sort_m7EF532E936D55845DAAC606C0A214FE48EBF8584_AdjustorThunk (RuntimeObject* __this, Func_3_t3E644C82345CE04737DA5CDE018481FE0A88F821* ___0_compare, const RuntimeMethod* method)
{
	WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87>(__this);
	WorkSlice_1_Sort_m7EF532E936D55845DAAC606C0A214FE48EBF8584(_thisAdjusted, ___0_compare, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 6455
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		intptr_t L_0 = __this->___handle;
		bool L_1;
		L_1 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline(L_0, 0, NULL);
		return L_1;
	}
}
// Method Definition Index: 6459
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0;
		L_0 = GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline(__this, NULL);
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_1 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral4EBC86E0EACFCA522AEB82874860D0E248D782A5)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_RuntimeMethod_var)));
	}

IL_0013:
	{
		intptr_t L_2 = __this->___handle;
		bool L_3;
		L_3 = GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline(L_2, NULL);
		if (!L_3)
		{
			goto IL_002c;
		}
	}
	{
		intptr_t L_4 = __this->___handle;
		RuntimeObject* L_5;
		L_5 = GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline(L_4, NULL);
		return L_5;
	}

IL_002c:
	{
		intptr_t L_6 = __this->___handle;
		RuntimeObject* L_7;
		L_7 = GCHandle_GetTarget_mE0AF851834410E2AEA6285B2497751570236C794(L_6, NULL);
		return L_7;
	}
}
// Method Definition Index: 6460
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GCHandle_set_Target_m1DB05E14910747D2A74ACEB4C48028C4AEBFCF3D_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		intptr_t L_0 = __this->___handle;
		bool L_1;
		L_1 = GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_001a;
		}
	}
	{
		intptr_t L_2 = __this->___handle;
		RuntimeObject* L_3 = ___0_value;
		GCHandle_SetRef_m89BDD13EED80A828682061BEF6D21F334AE45FC7_inline(L_2, L_3, NULL);
		return;
	}

IL_001a:
	{
		RuntimeObject* L_4 = ___0_value;
		intptr_t L_5 = __this->___handle;
		intptr_t L_6;
		L_6 = GCHandle_GetTargetHandle_mE33A9DC8A8FA880F9CAA057300E28BC8AE743CED(L_4, L_5, (-1), NULL);
		__this->___handle = L_6;
		return;
	}
}
// Method Definition Index: 9142
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* EqualityComparer_1_get_Default_mC0B29FC6AFED03D8A30BE41AC4BEC15DCF6AA9F8_gshared_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* V_0 = NULL;
	{
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_0 = ((EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mFA29AAFB8E37E401F19B2D5CC3E3C877B467E449(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t7A1FD25973851CA8703B3D65A407E44535B20581* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_gshared_inline (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m7A854E6D9D4EC168C4E21B19E4EC450FE72FC7EE_gshared_inline (Func_2_tE8C03B34A75321160F6D3EFCB01F9346EC7F21C7* __this, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDA1881613DBD7FA5B08D09294EC8EC31432B6856_gshared_inline (Func_2_t3E602B1155E686D3D1F6672128944CD3D6D9B6FA* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_gshared_inline (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD Enumerator_get_Current_m932259DC5443095A2D7AE244692FBCCD52A92261_gshared_inline (Enumerator_t70B197A0E6BB9C539CCD911D9CF29D8A4D917AF0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ControlItem_t25B2C46F52E78ADC5F54903F9E769364B02CD4AD L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mA36D1BA21683C3AFBC797DE6DF55593C8B8E0068_gshared_inline (Func_2_t135085FEAA39127D86C31D5991376887D3C220A9* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m90CB56B8B7978D05AAC723D65711310923B95704_gshared_inline (Func_2_t360CEA2886A09A4DD9E9C68DA8F1AD5A06089A08* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m879007C7AF8C186D82882ABA27C2ADC5B2FAC60A_gshared_inline (Func_2_t44CF4C3B1575173D918F721CADA68651C714A9E4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m4DF4F7C778C6FA0551F7553C2CDAEC9FC552AFBC_gshared_inline (Func_2_t653EDD14312DC25B03C1761015E5AE2456B9EE41* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m0B2454FA47AA37FEEC2DD61C2B5F00B6A14DB99A_gshared_inline (Func_2_tDAEC9671C704C3E23EF9651712FCCA0F3C1BDE3B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m858184794EB5168858FAC26769D630B0DB7B6748_gshared_inline (Func_2_t98F39575E3E0D3F315C6098F2B0FEACE3AEEF619* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m726B5D759A9573CA3EB19FA49313A307C51D4B6C_gshared_inline (Func_2_t9BBD5547216ABBB82D70EB4C1FA7F517AF448F22* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mE614A7DC65963CF49B99A00CB3E322972406CADD_gshared_inline (Func_2_tA04E383BDB9E2915D5B77AB3E646AF2DAB54A470* __this, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mC47A32134FE9D29EC4CB4F0748C0D9BC7308E4AE_gshared_inline (Func_2_tCFF3F4E33A60C27D5C04065F0BF14F51AD43B4AB* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m98BD0C55A1CD06D39C058CD5ECB1A06EBBC93838_gshared_inline (Func_2_t45E13AF8F7E5050E1CB2DB876E7C6C107B7FAC0E* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m5AF9E427A2C748831740CBA7F1CC50ED083E0971_gshared_inline (Func_2_tC0C363D6B853A4E2B590FE839945A8E90696D852* __this, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_gshared_inline (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mDDAE5E08C41E5668036677ED209B850CC6547292_gshared_inline (Func_2_t34787AB6BB8F2217CFED1101834AAAEFFEC13115* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mFA1BD30AA44BC4B0A9A749D71A987E6039436F53_gshared_inline (Func_2_t7A8BAB775E0F660CBF09C94C4C4676035EB49C76* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m77C320974BB0E8AFA1A7C39B514DDD8C06942AC5_gshared_inline (Func_2_t1786BA7CF27B123F6CFAA174EE698F743702757F* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, Substring_t2E16755269E6716C22074D6BC0A9099915E67849, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mA098B5996B6AE11EADA0A2F2DE377135468CEBAC_gshared_inline (Func_2_t6E897C5FF3BC8DDD4F3C18D3DFB83BDB8E4F9D2B* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, Substring_t2E16755269E6716C22074D6BC0A9099915E67849, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mB0BE6E22A6AD4CB9AB1B38930D3CC73E83094956_gshared_inline (Func_2_t6E40C6E318E44840C4860295F2101D9C12060C05* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, Substring_t2E16755269E6716C22074D6BC0A9099915E67849, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m8B551097217DFF5F72DACB7AA2A8BD5C739B7539_gshared_inline (Func_2_t4C195488A5D792CBE75E9F42017C517B156FB938* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_gshared_inline (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m36B8F113FD824518C95D724A04CD9EBE4EA4B89F_gshared_inline (Func_2_t36FB4A17A64C7F0152DC723CD532EEBF06F0B8DE* __this, int32_t ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_mEF9FB08DE4E3C95C6F5B1E856588DB02767A2DBD_gshared_inline (Func_2_t8C838EFDB6D66D8E9422A742711EAED0C3B7A899* __this, int32_t ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_mAACBBFA8D66C59AEFE34A5D4C504C6AA2848706C_gshared_inline (Func_2_t1E34B110B5504B16CB85FA04BDBC45E0B27C7E9A* __this, int32_t ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m60AC8696E0B36FEA3C3F1A9818798A3D18953D63_gshared_inline (Func_2_t93FE63D487003DC89C264F70099E05071B9C1169* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, JsonValue_t01DB320267C848E729A400EF2345979978F851D2, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Func_2_Invoke_m7C8D770BA29067A536942979753FAB53ED84A348_gshared_inline (Func_2_t6FD5B0E57F9B999DF2B1B1566A80ECD9AF78E595* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*FunctionPointerType) (RuntimeObject*, JsonValue_t01DB320267C848E729A400EF2345979978F851D2, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m6FC84CCA1E1537AEB97A5251183BC4A54093DFB7_gshared_inline (Func_2_t49F448C3C26EF4E9FB3C8739F33E4639531AA4C4* __this, JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, JsonValue_t01DB320267C848E729A400EF2345979978F851D2, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 Enumerator_get_Current_mFED85C73E83B80F77C323CED265F927D8F56A4C2_gshared_inline (Enumerator_t31AEF55A734D53971B425592C0A1C48934F81E01* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 Enumerator_get_Current_m6E5830352E5082086B6B8F79AB4DABC2A18414A3_gshared_inline (Enumerator_tB7F1A96A58CED8A263DA757B6D85EB0C1339F58D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 Enumerator_get_Current_mE64095D45062ABD3FE097C12C8A767F4378A3658_gshared_inline (Enumerator_t8A6E0A03FA966D5367776FAD5C06D879D186F054* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NameAndParameters_t8F37102128EFD31CA57808AE6E3D1244758DEA01 L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED Enumerator_get_Current_m83264A170B9E2284E4A91DD95D9E58A4AC7A065D_gshared_inline (Enumerator_t4FC6C6A75A6B5AFB8EDA87B7A8DA147830118B06* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NamedValue_t1D89B1ACD11D2B5284666865014E67683742B8ED L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_gshared_inline (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Substring_t2E16755269E6716C22074D6BC0A9099915E67849 Enumerator_get_Current_m543479141C23CB5A761FFAE440388CA38F12F73A_gshared_inline (Enumerator_tE3E77E493115DC420CF9F8E1A9DBCBE1A2DF1785* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Enumerator_get_Current_m27A9B9D3732FA85AE5063328B42817D18F991988_gshared_inline (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 8989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR JsonValue_t01DB320267C848E729A400EF2345979978F851D2 Enumerator_get_Current_m9F9305DFA7957A66E104431A3EB3D5C071B4587D_gshared_inline (Enumerator_t06B71EF17663E35C7B0EA1A12263D9A5C5E116EB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		JsonValue_t01DB320267C848E729A400EF2345979978F851D2 L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 37461
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_mCDE5BAF472BC1BEBC9D091F532AC1A07D65DB0BC_gshared_inline (WorkSlice_1_tDC724EEF28BD2F2E2B6498F1FDB285F8CCF34A44* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		return L_0;
	}
}
// Method Definition Index: 37461
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_m7212817506EACBA1AB0D914DE401C6FA05F0DD9D_gshared_inline (WorkSlice_1_t95249C8534D20AFEA3985723537EDE6E5BF06809* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		return L_0;
	}
}
// Method Definition Index: 37461
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t WorkSlice_1_get_length_m0E5769CB5B052657E7327DCAD0F2CA104327D7D8_gshared_inline (WorkSlice_1_t667B566D7F9D6CCD86634FB4157540E5A9C14E87* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Length;
		return L_0;
	}
}
// Method Definition Index: 3235
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		intptr_t L_0 = ___0_value1;
		intptr_t L_1 = ___1_value2;
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 6458
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline (intptr_t ___0_handle, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		intptr_t L_0 = ___0_handle;
		intptr_t L_1 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(1,NULL));
		intptr_t L_2 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((intptr_t)((intptr_t)(L_0&L_1))) == ((intptr_t)L_2))? 1 : 0);
	}
}
// Method Definition Index: 6456
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline (intptr_t ___0_handle, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		intptr_t L_0 = ___0_handle;
		void* L_1;
		L_1 = IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF(L_0, NULL);
		RuntimeObject** L_2;
		L_2 = il2cpp_unsafe_as_ref<RuntimeObject*>((intptr_t*)L_1);
		RuntimeObject* L_3 = il2cpp_codegen_ldind<RuntimeObject*, RuntimeObject*>(L_2);
		return L_3;
	}
}
// Method Definition Index: 6457
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GCHandle_SetRef_m89BDD13EED80A828682061BEF6D21F334AE45FC7_inline (intptr_t ___0_handle, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		intptr_t L_0 = ___0_handle;
		void* L_1;
		L_1 = IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF(L_0, NULL);
		RuntimeObject** L_2;
		L_2 = il2cpp_unsafe_as_ref<RuntimeObject*>((intptr_t*)L_1);
		RuntimeObject* L_3 = ___1_value;
		il2cpp_codegen_stind<RuntimeObject*>((RuntimeObject**)L_2, (RuntimeObject*)L_3);
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_2, (void*)(RuntimeObject*)L_3);
		return;
	}
}
