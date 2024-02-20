function Component()
{
	// default constructor
}

Component.prototype.createOperations = function()
{
	component.createOperations();
	if(systemInfo.productType === "windows")
	{
		component.addOperation(
			"CreateShortcut",
			"@TargetDir@/exampleApp",
			"@StartMenuDir@/exampleApp.lnk",
			"workingDirectory=@TargetDir@",
			"iconPath=@TargetDir@/main_icon.ico");
	}
}